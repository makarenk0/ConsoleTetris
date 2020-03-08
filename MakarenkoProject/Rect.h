#pragma once
#include <ctime>
class Rect
{
private:
	int x1, y1, x2, y2;
public:
	Rect(int top = 0, int left = 0, int bottom = 0, int right = 0);
	Rect(Rect&);
	~Rect();
	const int& getX1();
	const int& getX2();
	const int& getY1();
	const int& getY2();
	
	void moveRect(int deltaX, int deltaY);
};

