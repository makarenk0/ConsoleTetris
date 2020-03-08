#include "Map.h"
#include <iostream>



Map::Map(int x, int y, int width, int height, int rectWidth) : _x(x), _y(y), _width(width), _height(height), _rectWidth(rectWidth),
_bounds(y, x, y+height, x+width)
{
	_rectsInHeight = height / rectWidth;
	_rectsInWidth = width / rectWidth;
	size = _rectsInHeight * _rectsInWidth;
	_mapData = new Rect*[size];
	for (int i = 0; i < size; i++) {
		_mapData[i] = nullptr;
	}
	
	b.top = _bounds.getY1();
	b.left = _bounds.getX1();
	b.bottom = _bounds.getY2();
	b.right = _bounds.getX2();
	hPen1 = CreatePen(BS_SOLID, 1, RGB(0, 0, 255));
}

void Map::Draw(HDC& hdc)
{
	FrameRect(hdc, &b, (HBRUSH)hPen1);
	for (int i = 0; i < size; i++) {
		if (_mapData[i] != nullptr) {
			Rectangle(hdc, _mapData[i]->getX1(), _mapData[i]->getY1(), _mapData[i]->getX2(), _mapData[i]->getY2());
		}
	}
}

bool Map::Update(Part* movingPart)
{
	if (!canMove(0, _rectWidth, movingPart)) {
		for (auto i : movingPart->getRects()) {
			int number = ((i->getX1()-_x) / _rectWidth) + ((i->getY1()-_y) / _rectWidth) * _rectsInWidth;
			_mapData[number] = i;
		}
		checkDeletingRows();
		return true;
	}
	return false;
}

void Map::deleteRow(int y)
{
	for (int i = 0; i < _rectsInWidth; i++) {
		delete _mapData[y * _rectsInWidth + i];
		_mapData[y * _rectsInWidth + i] = nullptr;
	}
	for (int i = y * _rectsInWidth; i > 0; i--) {
		if (_mapData[i] != nullptr) {
			_mapData[i + _rectsInWidth] = _mapData[i];
			_mapData[i + _rectsInWidth]->moveRect(0, _rectWidth);
			_mapData[i] = nullptr;
		}
	}
}

void Map::checkDeletingRows()
{
	int counter = 0;
	for (int i = 0; i < _rectsInHeight; i++) {
		bool toDelete = true;
		for (int j = 0; j < _rectsInWidth; j++) {
			if (_mapData[i * _rectsInWidth + j] == nullptr) {
				toDelete = false;
				break;
			}
		}
		if (toDelete) {
			++counter;
			deleteRow(i);
		}
	}
	_score += counter * 100;
}

bool Map::canMove(int dx, int dy, Part* movingPart)
{
	for (auto i : movingPart->getRects()) {
		if (i->getX1() + dx<_x || i->getX2() + dx > _x + _width) return false;
		if (i->getY2() + dy>_y + _height) return false;
		if (_mapData[((i->getX1()+dx - _x) / _rectWidth) + ((i->getY1()+dy - _y) / _rectWidth) * _rectsInWidth] != nullptr) return false;
	}
	return true;
}

bool Map::canRotate(Part* movingPart)
{
	int rotatingX = movingPart->getRects()[1]->getX1();
	int rotatingY = movingPart->getRects()[1]->getY1();
	for (auto i : movingPart->getRects()) {
		int X = rotatingX - (i->getY1() - rotatingY);
		int Y = rotatingY + (i->getX1() - rotatingX);
		if (!canMove(X - i->getX1(), Y - i->getY1(), movingPart)) {
			return false;
		}
	}
	return true;
}

void Map::printScore()
{
	printf("\r%80c\r", ' ');
	std::cout << "Score: " << _score;
}
