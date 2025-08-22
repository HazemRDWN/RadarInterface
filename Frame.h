#pragma once

#include <iostream>
#include <vector>
#include "Point.h"

class Frame {

private:

	const int width = 100; 
	const int height = 50; 

	void printFrame(std::vector<std::vector<std::string>> hits) const;

public:

	void renderFrame(std::vector<Point> hits, int size) const;

	int getWidth() const;
	int getHeight() const;

};