#include "Point.h"
#include <cstdlib>

int Point::Xcoordinate(double distance, double angle) const {

	double radianAngle = angle * (22.00 / 7.00) / 180.00;

	double cartesian = distance * cos(radianAngle); //Get the cartesian coordinate from the polar coordinate

	int console = cartesian + (frameWidth / 2); //Translate the origin to the center of the console

	return console;

}

int Point::Ycoordinate(double distance, double angle) const {

	double radianAngle = angle * (22.00 / 7.00) / 180.00;

	double cartesian = distance * sin(radianAngle);

	int console = frameHeight - cartesian;

	return console;

}

Point::Point(): X(1024), Y(1024) {} //Default to 1024 because that is the highest reading the sensor sends
Point::Point(double Angle, double Distance, int Width, int Height): frameWidth(Width), frameHeight(Height), X(Xcoordinate(Distance, Angle)), Y(Ycoordinate(Distance, Angle)){}

int Point::getX() const { return X; }

int Point::getY() const { return Y; }
