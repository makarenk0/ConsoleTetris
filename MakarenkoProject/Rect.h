#pragma once
#include <ctime>
class Rect
{
private:
	int x1, y1, x2, y2;
public:
	Rect(int top, int left, int bottom, int right);
	const int& getX1();
	const int& getX2();
	const int& getY1();
	const int& getY2();
	
	void moveRect(int deltaX, int deltaY);
};

