#include "Part.h"




Part::Part(Part& p) : _updateGravityTime(p._updateGravityTime), _updateInteractionTime(p._updateInteractionTime), _width(p._width)
{
	for (auto i : p.rects) {
		rects.push_back(new Rect(*i));
	}
}

std::vector<Rect*>& Part::getRects()
{
	return rects;
}

Part::Part(int x, int y, int width, float updateGravityTime, float updateInteractionTime) : _width(width), _updateGravityTime(updateGravityTime), _updateInteractionTime(updateInteractionTime)
{
	srand(time(0));
	int patternId = rand() % 5;
	size_t s = 0;
	--s;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (patterns[patternId][i*4 + j]&&s>=0) {
				rects.push_back(new Rect(y + width * i, x + width * j, y + width * i + width, x + width * j + width));
				--s;
			}
		}
	}
}


Part* Part::UpdateGravity(float dt, float boost)
{
	gravityTimer += dt;
	if (gravityTimer >= _updateGravityTime/boost) {
		Part* previous = new Part(*this);
		gravityTimer = 0;
		for (auto i : rects) {
			i->moveRect(0, _width);
		}
		return previous;
	}
	return nullptr;
}



Part* Part::UpdateInteraction(float dt, int dx, bool toRotate)
{
	interactionTimer += dt;
	if (interactionTimer >= _updateInteractionTime) {
		interactionTimer = 0;
		Part* previous = new Part(*this);
		if (dx != 0) {
			for (auto i : rects) {
				i->moveRect(dx, 0);
			}
			return previous;
		}
		if (toRotate) {
			Rotate();
			return previous;
		}
		
	}
	return nullptr;
}

void Part::Rotate()
{
	int rotatingX = rects[1]->getX1();
	int rotatingY = rects[1]->getY1();
	for (auto i : rects) {
		int X = rotatingX - (i->getY1() - rotatingY);
		int Y = rotatingY + (i->getX1() - rotatingX);
		i->moveRect(X - i->getX1(), Y - i->getY1());
	}
}

void Part::Draw(HDC& hdc)
{
	for (auto i : rects) {
		Rectangle(hdc, i->getX1(), i->getY1(), i->getX2(), i->getY2());
	}
}

void Part::Clear(HDC& hdc)
{
	for (auto i : rects) {
		RECT r;
		r.left = i->getX1();
		r.top = i->getY1();
		r.right = i->getX2();
		r.bottom = i->getY2();
		FillRect(hdc, &r, (HBRUSH)CreateSolidBrush(RGB(12, 12, 12)));
	}
}

