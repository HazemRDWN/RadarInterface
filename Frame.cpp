#include "Frame.h"

using namespace std;

Frame::Frame(): width(100), height(50) {

	VerticalBounds = repeat("* ", width); //Call the repeat function to draw the upper and Lower borders
	InnerSpace = repeat("  ", (width - 2)); //Call the repeat function to draw empty space to use in a line that is known to have no hits

}

Frame::Frame(int Width, int Height): width(Width), height(Height) {

	VerticalBounds = repeat("* ", width);
	InnerSpace = repeat("  ", (width - 2));

}

int Frame::getHeight() { return height; }

int Frame::getWidth() { return width; }

string Frame::repeat(std::string String, int times) {

	string result = String;

	for (int i = 0; i < times; i++) {

		result += String;

	}

	return result;

}

void Frame::renderFrame(Point& hit) {

	//Visualizes hits given coordinates starting from the top left, each centimeter in the X-axis is a space and each centimeter in the Y-axis is a new line

	for (int y = 0; y <= height; y++) {

		if (hit.getY() == y && y != 0 && y != height) { //If there is a hit in this line and it does not overlap with the upper and lower borders draw it character by character

			for (int x = 0; x <= width; x++) {

				if (x == 0) {
					//Draw left border

					cout << "* ";

				}
				else if (0 < x && x < width) {
					//Among the borders if this is where the collision was detected draw an x, otherwise draw empty space

					if (x == hit.getX() && y == hit.getY()) {

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
		else if (y == 0 || y == height) { //If we are at the top or bottom of the frame draw the upper or lower borders

			cout << VerticalBounds;

			cout << endl;

		}
		else { //If we are in the middle of the frame draw the right and left borders with empty space in-between

			cout << "* " << InnerSpace << "*";

			cout << endl;

		}

	}

}