# BinKey
A DIY binary keyboard.

## Required:
* PCB (gerber file available from this repo, which can be printed by services like JLCPCB)
* 3 keyboard switches (Preferably PCB-mount, but case-mount works too)
* Teensy 4.0
* Firmware (also available from this repo)
* Soldering tools
* GPIO header connectors (TODO: find type of these)

## How to build:
1. Solder the Teensy 4.0 and the switches onto the board
  1. Only pins 20, 21, 22, and GND need to be soldered 
2. Download and set up [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) to allow you to flash the firmware
3. Connect the keyboard to your computer with USB
4. Open the firmware in the Arduino studio
  1. Go to Tools and change "Board" to "Teensy 4.0", and "USB Type" to "Keyboard"
  2. Then go to Sketch and Upload

Your keyboard should be ready to go
