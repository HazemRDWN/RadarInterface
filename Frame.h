#pragma once

#include <iostream>
#include <vector>
#include "Point.h"

class Frame {

private:

	const int width = 100; 
	const int height = 50; 

public:

	bool isWithinBorder(Point point);

	void renderFrame(Point hits[], int size);

	int getWidth();
	int getHeight();

};