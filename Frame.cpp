#include "Frame.h"
#include <string>

using namespace std;

int Frame::getHeight() { return height; }

int Frame::getWidth() { return width; }

bool Frame::isWithinBorder(Point point) {

	if (point.getX() < (width - 1) && point.getY() < (height - 1) && point.getX() > 0 && point.getY() > 0) {

		return true;

	} 
	else { return false; }

}

void Frame::renderFrame(Point hits[], int size) { //Visualizes hits given coordinates starting from the top left, each centimeter in the X-axis is a space and each centimeter in the Y-axis is a new line

	vector<vector<string>> frameArray(height, vector<string>(width, "  "));

	for (int pointIndex = 0; pointIndex < size; pointIndex++) { //Mapping all the hits

		if (isWithinBorder(hits[pointIndex])) {

			frameArray[hits[pointIndex].getY()][hits[pointIndex].getX()] = "X ";

		}

	}

	for (int x = 0; x < width; x++) { 

		frameArray[0][x] = "* "; //Mapping the upper border

		frameArray[height - 1][x] = "* "; //Mapping the lower border

	}

	for (int YframeIndex = 0; YframeIndex < height; YframeIndex++) {

		string Mark = "* - ";

		bool distanceToMark = (YframeIndex == 39 || YframeIndex == 29 || YframeIndex == 19 || YframeIndex == 9);

		if (distanceToMark) {

			string DistanceNum = to_string(((height - 1) - YframeIndex)); //(height - 1) gives the actual last Y-coordinate since frameArray starts indexing from zero

			Mark += DistanceNum + "cm";

			frameArray[YframeIndex][width - 1] = Mark;

			frameArray[YframeIndex][0] = "* "; //Mapping the left border

		}
		else {

			frameArray[YframeIndex][width - 1] = "* "; //Mapping the right border

			frameArray[YframeIndex][0] = "* ";

		}

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