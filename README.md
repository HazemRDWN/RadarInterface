This program is a CLI interface that uses ASCII characters to visualize data sent from an ultrasonic sensor made using an ESP8266, servo and an ultrasonic sensor.

To use this program simply compile and run the main.cpp file, make sure the ESP is connected to the appropriate port (in the current code it would be COM8, if you're unsure of the COM port your ESP is connected to you can check in the device manager). 
Make sure the ESP is sending over serial with 115200 baud rate and that no other program is reading serial data aside from this RadarInterface.
