#pragma once

#include <iostream>
#include "Point.h"

class Frame {

private:

	int width;
	int height;

	std::string VerticalBounds;
	std::string InnerSpace;

	std::string repeat(std::string String, int times);

public:

	Frame();
	Frame(int Width, int Height);

	void renderFrame(Point& hit);

	int getWidth();
	int getHeight();

};