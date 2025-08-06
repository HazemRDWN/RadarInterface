#include <serial/serial.h> //To read from serial
#include <cstdlib> //To use cls
#include <iostream>
#include "Frame.h"
#include "Point.h"

using namespace std;
using namespace serial;

int main() {

    Frame frame;

    string sentence;
    size_t delimiterPos;

    double distance;
    double angle;

    try {
        Serial esp("COM8", 115200, Timeout::simpleTimeout(600));

        while (true) {

			sentence = esp.readline();
			delimiterPos = sentence.find(','); //size_t is an unsigned variable type

			distance = stof(sentence.substr(0, delimiterPos));
			angle = stof(sentence.substr(delimiterPos + 1));

            Point hit(angle, distance, frame.getWidth(), frame.getHeight());

			frame.renderFrame(hit);
			system("cls");

        }
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}