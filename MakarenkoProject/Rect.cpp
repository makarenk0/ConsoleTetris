#include "Rect.h"
#include <iostream>

Rect::Rect(int top, int left, int bottom, int right) : x1(left), y1(top), x2(right), y2(bottom)
{

}

Rect::Rect(Rect& r) : x1(r.getX1()), y1(r.getY1()), x2(r.getX2()), y2(r.getY2())
{

}

Rect::~Rect()
{
}

const int& Rect::getX1()
{
	return x1;
}

const int& Rect::getX2()
{
	return x2;
}

const int& Rect::getY1()
{
	return y1;
}

const int& Rect::getY2()
{
	return y2;
}

void Rect::moveRect(int deltaX, int deltaY)
{
	x1 += deltaX;
	x2 += deltaX;
	y1 += deltaY;
	y2 += deltaY;
}



