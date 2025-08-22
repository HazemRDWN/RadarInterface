#pragma once

class Point {

private:

	int X;
	int Y;

	int frameWidth; //Frame dimensions needed to translate the X and Y coordinates accordingly
	int frameHeight;

	int Xcoordinate(double distance, double angle) const;
	int Ycoordinate(double distance, double angle) const;

public:

	Point();
	Point(double Angle, double Distance, int Width, int Height);

	int getX() const;
	int getY() const;

};