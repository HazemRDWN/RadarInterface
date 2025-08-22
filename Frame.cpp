#include "Frame.h"
#include <string>

using namespace std;

int Frame::getHeight() { return height; }

int Frame::getWidth() { return width; }

void Frame::renderFrame(vector<Point> hits, int size) { //Visualizes hits given coordinates starting from the top left, each centimeter in the X-axis is a space and each centimeter in the Y-axis is a new line

	vector<vector<string>> frameArray(height, vector<string>(width, "  "));

	for (int pointIndex = 0; pointIndex < size; pointIndex++) { //Mapping all the hits

		bool isWithinBorder = (hits[pointIndex].getX() < (width - 1) && hits[pointIndex].getY() < (height - 1) && hits[pointIndex].getX() > 0 && hits[pointIndex].getY() > 0);

		if (isWithinBorder) {

			frameArray[hits[pointIndex].getY()][hits[pointIndex].getX()] = "X ";

		}

	}

	for (int xFrameIndex = 0; xFrameIndex < width; xFrameIndex++) {

		frameArray[0][xFrameIndex] = "* "; //Mapping the upper border

		frameArray[height - 1][xFrameIndex] = "* "; //Mapping the lower border

	}

	for (int yFrameIndex = 0; yFrameIndex < height; yFrameIndex++) {

		string Mark = "* - ";

		bool indexToMark = (yFrameIndex == 39 || yFrameIndex == 29 || yFrameIndex == 19 || yFrameIndex == 9);

		if (indexToMark) {

			string DistanceNum = to_string(((height - 1) - yFrameIndex)); //(height - 1) gives the actual last Y-coordinate since frameArray starts indexing from zero

			Mark += DistanceNum + "cm";

			frameArray[yFrameIndex][width - 1] = Mark;

			frameArray[yFrameIndex][0] = "* "; //Mapping the left border

		}
		else {

			frameArray[yFrameIndex][width - 1] = "* "; //Mapping the right border

			frameArray[yFrameIndex][0] = "* ";

		}

	}

	string Output;

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			Output += frameArray[y][x];

		}

		Output += "\n";

	}

	cout << Output;

}