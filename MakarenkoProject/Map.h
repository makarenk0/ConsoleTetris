#pragma once
#include "Rect.h"
#include "Part.h"
class Map
{
private:
	Rect** _mapData;
	Rect _bounds;
	size_t size;
	int _rectsInHeight, _rectsInWidth;
	int _x, _y, _width, _height, _rectWidth;
	RECT b;
	HPEN hPen1;
	void deleteRow(int y);
	void checkDeletingRows();
	int _score = 0;
public:
	Map(int x, int y, int width, int height, int rectWidth);
	void Draw(HDC& hdc);
	bool Update(Part* movingPart);
	bool canMove(int dx, int dy, Part* movingPart);
	bool canRotate(Part* movingPart);
	void printScore();
};

