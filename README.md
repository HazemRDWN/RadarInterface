# This program is a CLI interface that uses ASCII characters to visualize data sent from an ultrasonic radar made using an ESP8266, servo and an ultrasonic sensor.

## There are two ends in this system: 

- **The ESP end**: Where the ESP code runs and controls the servo and sensor, sending raw data (servo angle and distance from sensor).
- **The desktop end**: Where the interface runs and translates raw data into useful information.

## To get started you'll need to setup both ends:

- **The ESP end**: Open the ESP folder and upload the Radar.io sketch on the ESP8266. Make sure the ESP is connected to the appropriate port *(in the current code it would be COM8, if you're unsure of the COM port your ESP is connected to you can check in the device manager)*, sending over serial with 115200 baud rate and that no other program is reading serial data aside from this RadarInterface.
- **The desktop end**: simply compile and run the main.cpp file.

*A schematic of the radar connections will be provided soon*

# Development notes:
