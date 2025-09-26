# This program is a CLI interface that uses ASCII characters to visualize data sent from an ultrasonic radar.

## There are two ends in this system: 

- **The ESP end**: Where the ESP code runs and controls the servo and sensor, sending raw data (servo angle and distance from sensor).
- **The desktop end**: Where the interface runs and translates raw data into useful visual information.

## To get started you'll need to setup both ends:

- **The ESP end**: Open the ESP folder and upload the Radar.io sketch on the ESP8266. Make sure the ESP is sending over serial with 115200 baud rate and that no other program is reading serial data aside from this RadarInterface.
- **The desktop end**: simply compile and run the main.cpp file.

<img width="1169" height="827" alt="Schematic_Ultrasonic-radar_2025-09-26" src="https://github.com/user-attachments/assets/555345b6-53d2-48ed-b810-e1f9f9620be6" />

# Development notes:

- The ultra-sonic sensor's operating voltage is 5V but at that voltage it would send the ECHO signal to the ESP at 5V, that is a problem because the ESP's GPIO pins use 3V logic.
    - *This should be solved by connecting a resistor in series between the ECHO and the GPIO pins, while keeping the sensor at operating voltage. In my case a resistor was not available so the sensor operates at 3V coming from the ESP.*

- The frame rendering was done on the ESP in the beginning which resulted in the frames appearing slowly. This was caused by the large amount of serial prints being sent in a short time crowding the buffer resulting in a queue.
    - *Solution: transferring the frame rendering to the device that will show the frames, the computer, allowing the ESP to only send angle and distance readings.*

- The frames were being printed character by character in the console which was very ineffecient and showed while the frame was being displayed.
    - *Solution: "pre-rendering" the lines that do not include hits and printing them entirely, only printing character by character in lines that include hits.*

- Showing more than one hit per frame was difficult to implement because the code was cluttered with loops, the logic barely held together.
    - *Solution: restructuring the logic into a way that was easier to follow and expand on, using a 2D vector to build the frame adding all the hits in their corresponding coordinates.*
