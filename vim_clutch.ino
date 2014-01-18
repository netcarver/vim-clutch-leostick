/*
 @author Netcarver
 @copyright Copyright 2014 Netcarver
 @license MIT

Connect a normally open push-to-make footswitch between D0 and GND on a Freetronics LeoStick.
*/

const byte switchPin = 0;     // footswitch between this pin and gnd.
const byte ledPin    = 13;    // the pin that the LED is attached to
byte new_sample;
byte previous_sample = HIGH;
long time = 0;
long debounce = 100;
byte switchState = HIGH;

void setup() {
  pinMode(switchPin, INPUT_PULLUP); // Use internal pullup
  pinMode(ledPin, OUTPUT);
  Keyboard.begin();
  digitalWrite(ledPin, LOW);        // LED off
}


void loop() {
  new_sample = digitalRead(switchPin);

  // compare the switchState to its previous state
  if (new_sample != previous_sample) {
      time = millis();
  }

  if ((millis() - time) > debounce) {
    if (new_sample != switchState) {
      // edge detected
      if (HIGH == new_sample) {
        footswitchLowToHigh();
      } else {
        footswitchHighToLow();
      }
    }
    
    switchState = new_sample;
  }
  previous_sample = new_sample;
}


void footswitchLowToHigh() {
  Keyboard.press(177);   // The escape key, Vim to normal mode.
  flashOnce();           // Side effect of a small delay.
  Keyboard.releaseAll();
}

void footswitchHighToLow() {
  Keyboard.press('i');   // Make Vim enter insert mode.
  flashOnce();           // Flash and delay.
  Keyboard.releaseAll();
}

void flashOnce() {
  digitalWrite(ledPin, HIGH);
  delay(10);
  digitalWrite(ledPin, LOW);
}
