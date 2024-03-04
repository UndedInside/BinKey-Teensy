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

## How to use:
When the BinKey is initially plugged in or a new firmware is flashed, the built-in debug LED will flash the morse code for "OK". This will let you know that the device is working. Once this has flashed up, simply type the ASCII (from MSB) for the character you would like to type and once all 8 bits have been entered the keypress will be sent to the computer. 

This can type uppercase, lowercase, numbers, and special characters. 'Delete' can also be sent, but I haven't tried any other mod keys like that. If you give it a try, let me know the results

## Troubleshooting:
### It's typing the wrong characters?
When flashing the keyboard with teensyduino, make sure to set the right keyboard layout with "Tools > Keyboard layout". Make sure this matches your computers keyboard layout to ensure you type the characters you're expecting.

### Sometimes it types nothing?
Unfortunately not every character is supported by the Teensy's Keyboard library. You can get a list of supported keys on the Teensy's website [here](https://www.pjrc.com/teensy/td_keyboard.html). I haven't yet taken the time to map out the supported keys but it's on my todo list. 


## TODO:
* Document the building stage better. Add pictures, maybe film a video
* Upload the updated PCBs. Test those first.
