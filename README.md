# Low Power Keypad Firmware

## Setup
- STM32F103C8 (BLUEPILL)
- matrix-keypad
- 433 MHz transmitter
- LEDs

## Theory of Operation
The device powers on, configures IO for wakeup, and enters low power mode STOP.  On pressing the "*" key on the matrix keypad, the device exits sleep mode and again is in RUN mode.  It begins a blocking polling routine accepting keypresses and appending them to a string. Once "#" is pressed the string is complete.  If the string matches a predetermined password the device will transmit the appropriate signal via the 433 MHz transmitter (in progress). This signal will "unlock" some access-controlled device. If the password does not match or 2 minutes expires the device configures IO for wakeup and again enters low power mode STOP.

## Building and Debugging
This project has a makefile that wraps the mbed-os build commands.  MBED-CLI tools need to be installed. Run 'mbed deploy' in the directory to update mbed-os to the proper version.  Once properly setup, call 'make' to build.

To debug, vscode cortex-debug extensions and JLINK tools are used.  Updates to the .vscode/settings.json file will be needed:
```
    "cortex-debug.armToolchainPath": "{your path here}/gcc-arm-none-eabi-9-2019-q4-major/bin/",
    "cortex-debug.JLinkGDBServerPath": "{your path here}/JLink_V662a/",
```