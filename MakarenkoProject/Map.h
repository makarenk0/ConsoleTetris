#pragma once
#include "Rect.h"
#include "Part.h"
class Map
{
private:
	Rect** _mapData;
	Rect _bounds;
	Part* _movingPart;
	int _rectsInHeight, _rectsInWidth;
	int _x, _y, _width, _height, _rectWidth;
	RECT b;
	HPEN hPen1;
public:
	Map(int x, int y, int width, int height, int rectWidth, Part* movingPart);
	void Draw(HDC& hdc);
	bool Update();
	bool canMove(int dx, int dy);
};

