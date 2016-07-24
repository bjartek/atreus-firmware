# Atreus keyboard firmware

This repository contains firmware (called TMK) loaded into its
controller to make the keyboard function. You can also use it to
customize its layout or behavior. This branch makes use of the latest TMK release.

The main differences are:

- Uses the latest branch of TMK
- Makes use of actions codes, vs. keymaps.
- Media keys enabled in build.
- Updated keymap macros so keymaps are very easy to define.
- The layers are not the same. I've been experimenting with it.
- Try to guess the USB interface based upon uname, using usbmodem1441 on mac
- If there is a keymap file that is the same as your username it is chosen by default
- Move macros defined by alex/audibleblink and bjartek/me into common.h

### Installing on Mac OS X

Install [homebrew](http://brew.sh/)

    $ brew tap osx-cross/avr
    $ brew install avrdude
    $ brew install teensy_loader_cli
    $ brew install avr-libc
    $ cd atreus
    $ make upload KEYMAP=qwerty

### Layout

Copy `keymap_qwerty.c` (or another) into a new file (if you name this file keymap_<username>.c it will be chosen by default) to create your new
layout, and change the `keymaps` array to place the actioncodes you want
in the positions you want.

The `FN_ARROW_LAYER` and `LAYER_TWO` macros correspond to the default
extra layers as defined in `keymap_common.h`; replace them with
`KEYMAP` calls if you want to customize these layers.

Look into `keymap_common.h` for some macros that make it easier to map keys.
For more details see the [TMK documentation](tmk/README.md).

### Compiling

This codebase defaults to targeting the most recent PCB-based design
of the Atreus which uses the A-Star microcontroller, but it can also
work with hand-wired boards that use the Teensy 2.

Keymaps are per default your username if it exists or qwerty.

USB interface on mac is usbmodem1441, else ttyACM0

Uploading to a Teensy 2 can be done with `OPT_DEFS=-DTEENSY make teensy
KEYMAP=qwerty`.

Getting to the bootloader on the Teensy is simpler;
if you can't do it in software simply press the hardware reset button
once.

### Bjartek layout
My layout is using a lot of dual purpose keys, that is the keys mean something when hold and another when pressed.
- all modifier keys are oneshot. Tap it and another key within a short while and the mod will be used for only that keypress
- holding down esc or enter will produce ralt. I map norwegian letters to ralt in os.
- i use 4 right hand only layers. I hold a key on the homerow on my left hand, the right is then a new layer. I use this for movement, numbers, fn keys and keyboard mouse.
- my only other full layer is switched when holding fn. (tappning fn yields tab). This layer is for all special symbols and Idea actions.
- on my right hand only lyaers i have bound some keys to several mods, so it easier to press difficult keybindngs in IDE. 
-

