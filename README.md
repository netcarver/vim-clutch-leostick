Vim-Clutch Using A Freetronics LeoStick.
========================================

A Vim-Clutch is a footswitch that allows you to easily switch modes in Vim. As far as I can tell the original idea can
be credited to [Aleksandr Levchuk](https://github.com/alevchuk/vim-clutch/blob/master/README.md) who used a modified USB
footswitch. I like Arduino and decided to see if I could do this using Arduino bits and pieces. In particular, a
LeoStick was used as it is very compact and it can act as a USB keyboard - allowing me to easily generate "keypresses"
that cause vim to mode switch.

What You Need
-------------

* A [LeoStick](http://www.freetronics.com/pages/leostick-getting-started-guide).
* The Arduino IDE (updated to allow uploads to a LeoStick.)
* A normally open push-to-make footswitch - non USB is fine. There are some very cheap Tattoo-PSU switches out there that
should do just fine.

Setup
-----

Connect your footswitch directly between D0 and GND on your LeoStick. Plug it into a USB port on you machine, launch the
Arduino IDE, load the provided .ino sketch then compile and upload it to your LeoStick. You should now have a working
Vim-Clutch.

Operation Within Vim
--------------------

Start vim as usual. When you want to enter insert mode just press and hold down the footswitch. When you've finished in
insert mode, release the footswitch.

The arduino sketch takes care of de-bouncing the footswitch and detecting the press and release of the switch. It
generates an ```i``` keypress when the switch is depressed and sends an ```<esc>``` keypress when it is released.

License
-------

MIT. See license.txt for more.
