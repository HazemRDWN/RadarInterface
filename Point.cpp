#include "Point.h"
#include <cstdlib>

int Point::Xcoordinate(double distance, double angle) {

	double cartesian = distance * cos(angle * (22.00 / 7.00) / 180.00); //Get the cartesian coordinate from the polar coordinate

	int console = cartesian + (frameWidth / 2); //Translate the origin to the center of the console

	return console;

}

int Point::Ycoordinate(double distance, double angle) {

	double cartesian = distance * sin(angle * (22.00 / 7.00) / 180.00);

	int console = frameHeight - cartesian;

	return console;

}

Point::Point(): Y(1024), X(1024) {} //Default to 1024 because that is the highest reading the sensor sends
Point::Point(double Angle, double Distance, int Width, int Height): X(Xcoordinate(Distance, Angle)), Y(Ycoordinate(Distance, Angle)), frameWidth(Width), frameHeight(Height){}

int Point::getX() { return X; }

int Point::getY() { return Y; }