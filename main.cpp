#include <serial/serial.h> //To read from serial
#include <cstdlib> //To use cls
#include <thread> 
#include <iostream>
#include "Frame.h"
#include "Point.h"

using namespace std;
using namespace serial;

void drawSweep(int angle, int frameWidth) {
    
    string sweepLine = "[ ";

    double angleCoverage = (angle / 180.00) * 100.00;
    double frameCoverage = 100 - ((angleCoverage / 100.00) * frameWidth);

    for (int x = 1; x < frameWidth; x++) {

        if (x == static_cast<int>(frameCoverage)) {

            sweepLine += "- ";

        }
        else if (x == (frameWidth - 1)) {

            sweepLine += "]";

        }
        else {

            sweepLine += "  ";

        }

    }

    cout << sweepLine;

}

int main() {

    Frame frame;

    string sentence;
    size_t delimiterPos; //size_t is an unsigned variable type

    const int pointsNumber = 91; //The radar rotates 2 degrees at a time. So after sweeping the 180 degrees it sends 91 readings or "points" including the zero angle.

    vector<Point> Points(pointsNumber); 

    double distance;
    double angle;

    try {

        Serial esp("COM8", 115200, Timeout::simpleTimeout(600));

        while (true) {

            std::chrono::microseconds timespan(1000);

            std::this_thread::sleep_for(timespan);

			sentence = esp.readline();

            try {

                delimiterPos = sentence.find(',');

                distance = stof(sentence.substr(0, delimiterPos));
                angle = stof(sentence.substr(delimiterPos + 1));

            }
            catch (const exception& e) {

                cerr << "Error: " << e.what() << endl;

            }

            Point newPoint(angle, distance, frame.getWidth(), frame.getHeight());

            size_t pointsIndex = angle / 2;

            Points[pointsIndex] = newPoint;

            system("cls");

			frame.renderFrame(Points, pointsNumber);

            drawSweep(angle, frame.getWidth());

        }
    }
    catch (const exception& e) {

        cerr << "Error: " << e.what() << endl;

    }

    return 0;
}