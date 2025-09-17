#include <serial/serial.h> //To read from serial
#include <cstdlib> //To use cls
#include <windows.h> //To listen to key press
#include <thread> 
#include <iostream>
#include "Frame.h"
#include "Point.h"

using namespace std;
using namespace serial;

bool validPort(string port) {

    try {

        cout << "Trying " << port << endl;

        Serial esp(port, 115200, Timeout::simpleTimeout(600));
        string sentence = esp.readline();

        size_t delimiterPos = sentence.find(':');
        string marker = sentence.substr(0, delimiterPos);

        if (marker == "RDR") {

            return true;

        }
        else { return false; }

    }
    catch (const exception& e) {

        cerr << "Error: " << e.what() << endl;
        return false;

    }

}

string findPort() {

    string port;

    for (int portNum = 1; portNum <= 10; portNum++) {

        port = "COM" + to_string(portNum);

        if (validPort(port)) {

            return port;

        }
        else {

            continue;

        }

    }

    throw runtime_error("Valid serial port not found.");

}

string getCOM() {

    while (true) {

        cout << " Ultrasonic Radar Interface. \n \n Select COM selection method (Baudrate should be set to 115200): \n 1.Manual input \n 2.Automatic detection (Slower) \n 3.Exit \n \n Press 'E' to exit once program is started. \n \n Enter selection number: ";
        string choice;
        cin >> choice;

        if (choice == "1") {

            system("cls");

            cout << "Enter COM number: ";
            string COMnumber;
            cin >> COMnumber;

            string COMport = "COM" + COMnumber;

            if (validPort(COMport)) { return COMport; }
            else {

                system("cls");

                cout << " Invalid COM number. \n \n";
                continue;

            }

        }

        else if (choice == "2") {

            system("cls");

            return findPort(); 
        
        }

        else if (choice == "3") {

            return "exit";

        }

        else { 
        
            system("cls");

            cout << " Invalid input. \n \n";
            continue;
        
        }

    }

}

int main() {

    Frame frame;

    string sentence;
    size_t delimiterPos; //size_t is an unsigned variable type
    size_t markerEnd;

    const int maxAngle = 180;
    const int angleStep = 2;

    int pointsNumber = (maxAngle / angleStep) + 1; //The radar rotates 2 degrees at a time. So after sweeping the 180 degrees it sends 90 readings or "points" plus the zero angle.

    vector<Point> points(pointsNumber); 

    double distance;
    double angle;

    try{

        string port = getCOM();

        if (port == "exit") {

            return 0;

        }
        else {

            Serial esp(port, 115200, Timeout::simpleTimeout(600));

            while (!GetAsyncKeyState('E')) {

                std::chrono::microseconds timespan(1000);

                std::this_thread::sleep_for(timespan);

                sentence = esp.readline();

                try {

                    delimiterPos = sentence.find(',');
                    markerEnd = sentence.find(':');

                    distance = stof(sentence.substr(markerEnd + 1, delimiterPos));
                    angle = stof(sentence.substr(delimiterPos + 1));

                    if (angle >= 0 && angle <= 180 && distance >= 0) {

                        Point newPoint(angle, distance, frame.getWidth(), frame.getHeight());

                        size_t pointsIndex = angle / 2;

                        points[pointsIndex] = newPoint;

                        system("cls");

                        frame.renderFrame(points, pointsNumber);

                        frame.drawSweep(angle, frame.getWidth());

                    }
                    else {

                        cerr << "Error: A reading is out of bounds.";

                    }

                }
                catch (const exception& e) {

                    cerr << "Error: " << e.what() << endl;
                    return 0;

                }

            }

        }

    }
    catch (const exception& e) {

        cerr << "Error: " << e.what() << endl;

    }

    return 0;
}