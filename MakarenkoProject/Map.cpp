#include "Map.h"

Map::Map(int x, int y, int width, int height, int rectWidth, Part* movingPart) : _x(x), _y(y), _width(width), _height(height), _rectWidth(rectWidth), _movingPart(movingPart),
_bounds(Rect(y, x, y+height, x+width))
{
	_rectsInHeight = height / rectWidth;
	_rectsInWidth = width / rectWidth;
	_mapData = new Rect * [_rectsInHeight * _rectsInWidth];
	
	b.top = _bounds.getY1();
	b.left = _bounds.getX1();
	b.bottom = _bounds.getY2();
	b.right = _bounds.getX2();
	hPen1 = CreatePen(BS_SOLID, 1, RGB(0, 0, 255));
}

void Map::Draw(HDC& hdc)
{
	FrameRect(hdc, &b, (HBRUSH)hPen1);
}

bool Map::Update()
{
	if (!canMove(0, _rectWidth)) {
		for (auto i : _movingPart->rects) {
			_mapData[(i->getX1() / _rectWidth) + (i->getY1() / _rectWidth) * _rectsInWidth] = i;
			
		}
		return true;
	}
	return false;
}

bool Map::canMove(int dx, int dy)
{
	
	for (auto i : _movingPart->rects) {
		if (i->getX1() + dx<_x || i->getX2() + dx > _x + _width) return false;
		if (i->getY2() + dy>_y + _height) return false;
	}
	return true;
}
