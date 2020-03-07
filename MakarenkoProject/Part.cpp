#include "Part.h"


Part::Part(int x, int y, int width, float updateTime) : _width(width), _updateTime(updateTime)
{
	srand(time(0));
	int patternId = rand() % 4;
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


void Part::Update(float dt, int dx)
{
	timer += dt;
	if (timer >= _updateTime) {
		timer = 0;
		for (auto i : rects) {
			i->moveRect(dx, _width);
		}
	}
}

void Part::Draw(HDC& hdc)
{
	for (auto i : rects) {
		Rectangle(hdc, i->getX1(), i->getY1(), i->getX2(), i->getY2());
	}
}

bool Part::inBounds(int x1, int y1, int x2, int y2)
{

	return false;
}


