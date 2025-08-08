#include "Frame.h"

using namespace std;

int Frame::getHeight() { return height; }

int Frame::getWidth() { return width; }

void Frame::renderFrame(Point hits[], int size) { //Visualizes hits given coordinates starting from the top left, each centimeter in the X-axis is a space and each centimeter in the Y-axis is a new line

	vector<vector<string>> frameArray(height, vector<string>(width, "  "));

	for (int pointIndex = 0; pointIndex < size; pointIndex++) { //Mapping all the hits

		if (hits[pointIndex].getX() < (width - 1) && hits[pointIndex].getY() < (height -1) && hits[pointIndex].getX() > 0 && hits[pointIndex].getY() > 0) {

			frameArray[hits[pointIndex].getY()][hits[pointIndex].getX()] = "X ";

			/*cout << "Y: " << hits[pointIndex].getY() << ", X: " << hits[pointIndex].getX() << endl;*/

		}

	}

	for (int x = 0; x < width; x++) { //Mapping the upper border

		frameArray[0][x] = "* ";

	}

	for (int x = 0; x < width; x++) { //Mapping the lower border

		frameArray[height - 1][x] = "* ";

	}

	for (int y = 0; y < height; y++) { //Mapping the left border

		frameArray[y][0] = "* ";

	}

	for (int y = 0; y < height; y++) { //Mapping the right border

		frameArray[y][width - 1] = "* ";

	}

	string Frame;

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			Frame += frameArray[y][x];

		}

		Frame += "\n";

	}

	cout << Frame;

}