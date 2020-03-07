#pragma once
#include "Rect.h"
#include <windows.h>
#include <stdlib.h>
#include <vector>

class Part
{
private:
	
	float timer = 0;
	const float _updateTime;
	const bool patterns[4][8] = {
		{1,1,1,1,0,0,0,0},
	    {0,1,1,0,1,1,0,0},
	    {1,1,0,0,1,1,0,0},
	    {1,1,1,0,0,0,1,0},
	};
	int _width;
public:
	std::vector<Rect*> rects;
	Part(int x, int y, int width, float updateTime);
	void Update(float dt, int dx);
	void Draw(HDC& hdc);
	bool inBounds(int x1, int y1, int x2, int y2);
};

