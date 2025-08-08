#include <serial/serial.h> //To read from serial
#include <cstdlib> //To use cls
#include <iostream>
#include "Frame.h"
#include "Point.h"

using namespace std;
using namespace serial;

int main() {

    Frame frame;
    int frameWidth = frame.getWidth();

    string sentence;
    size_t delimiterPos; //size_t is an unsigned variable type

    Point Points[90]; //The radar rotates 2 degrees at a time. So after sweeping the 180 degrees it sends 90 readings or "points".

    double distance;
    double angle;

    try {
        Serial esp("COM8", 115200, Timeout::simpleTimeout(600));

        while (true) {

			sentence = esp.readline();
			delimiterPos = sentence.find(','); 

			distance = stof(sentence.substr(0, delimiterPos));
			angle = stof(sentence.substr(delimiterPos + 1));

            Point newPoint(angle, distance, frameWidth, frame.getHeight());

            int index = (angle / 2) -1;

            Points[index] = newPoint;

			frame.renderFrame(Points, 90);
			system("cls");

        }
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}