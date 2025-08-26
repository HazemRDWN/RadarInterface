#include <serial/serial.h> //To read from serial
#include <cstdlib> //To use cls
#include <thread> 
#include <iostream>
#include "Frame.h"
#include "Point.h"

using namespace std;
using namespace serial;

int main() {

    Frame frame;

    string sentence;
    size_t delimiterPos; //size_t is an unsigned variable type

    const int maxAngle = 180;
    const int angleStep = 2;

    int pointsNumber = (maxAngle / angleStep) + 1; //The radar rotates 2 degrees at a time. So after sweeping the 180 degrees it sends 90 readings or "points" plus the zero angle.

    vector<Point> points(pointsNumber); 

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

            points[pointsIndex] = newPoint;

            system("cls");

			frame.renderFrame(points, pointsNumber);

            frame.drawSweep(angle, frame.getWidth());

        }
    }
    catch (const exception& e) {

        cerr << "Error: " << e.what() << endl;

    }

    return 0;
}