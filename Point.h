#pragma once

class Point {

private:

	int X;
	int Y;

	int frameWidth; //Frame dimensions needed to translate the X and Y coordinates accordingly
	int frameHeight;

	int Xcoordinate(double distance, double angle);
	int Ycoordinate(double distance, double angle);

public:

	Point(double Angle, double Distance, int Width, int Height);

	int getX();
	int getY();

};