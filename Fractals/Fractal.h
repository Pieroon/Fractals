#ifndef FRACTAL_H
#define FRACTAL_H

struct Point
{
public:
	int X;
	int Y;
};

class Fractal
{
public:
	int Level;
	Point p1;
	Point p2;
};
#endif