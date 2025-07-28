#include <serial/serial.h> //To read from serial
#include <cstdlib> //To use cls
#include <iostream>

using namespace std;
using namespace serial;

const int width = 100;
const int height = 50;

string repeat(string String, int times) { //Used to generate the width of the frame

	string result = String;

	for (int i = 0; i < times; i++) {

		result += String;

	}

	return result;

}

void frame(int& Horizontal, int& Vertical) {
	//Visualizes hits given coordinates starting from the top left, each centimeter in the X-axis is a space and each centimeter in the Y-axis is a new line

	string ULborders = repeat("* ", width); //Call the repeat function to draw the upper and lower borders
	string EmptySpace = repeat("  ", (width - 2)); //Call the repeat function to draw empty space to use in a line that is known to have no hits

	for (int y = 0; y <= height; y++) {

		if (Vertical == y && y != 0 && y != height) { //If there is a hit in this line and it does not overlap with the upper and lower borders draw it character by character

			for (int x = 0; x <= width; x++) {

				if (x == 0) {
					//Draw left border

					cout << "* ";

				}
				else if (0 < x && x < width) {
					//Among the borders if this is where the collision was detected draw an x, otherwise draw empty space

					//______________Maybe add delay here to give a chance for the XY coordinates to update_______________________
					//________Also try sending the ultrasonic signals here to update Horizontal and Vertical coordinates_________
					//_____________________________________Everything above is BS________________________________________________

					if (x == Horizontal && y == Vertical) {

						cout << "X ";

					}
					else {

						cout << "  ";

					}

				}
				else if (x == width) {
					//Draw right border

					cout << "* ";

				}

			}

			cout << endl;

		}
		else if (y == 0 || y == height){ //If we are at the top or bottom of the frame draw the upper or lower borders

			cout << ULborders;

			cout << endl;

		}
		else { //If we are in the middle of the frame draw the right and left borders with empty space in-between

			cout << "* " << EmptySpace << "*";

			cout << endl;

		}

	}

}

int Xcoordinate(double distance, double angle) {

	double cartesian = distance * cos(angle * (22.00 / 7.00) / 180.00); //Get the cartesian coordinate from the polar coordinate

	int console = cartesian + ((width + 1) / 2); //Translate the origin to the center of the console

	return console;

}

int Ycoordinate(double distance, double angle) {

	double cartesian = distance * sin(angle * (22.00 / 7.00) / 180.00);

	int console = -cartesian + (height - 2);

	return console;

}

int main() {

    try {
        Serial esp("COM8", 115200, Timeout::simpleTimeout(600));

        while (true) {

			//double distance = stof(esp.readline());

			//double angle = 95.00;

			string sentence = esp.readline();
			size_t delimiterPos = sentence.find(','); //size_t is an unsigned variable type

			double distance = stof(sentence.substr(0, delimiterPos));
			double angle = stof(sentence.substr(delimiterPos + 1));


			int x = Xcoordinate(distance, angle);
			int y = Ycoordinate(distance, angle);

			frame(x, y);
			system("cls");

        }
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}