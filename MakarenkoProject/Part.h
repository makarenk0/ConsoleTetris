#pragma once
#include "Rect.h"
#include <windows.h>
#include <stdlib.h>
#include <vector>

class Part
{
private:
	std::vector<Rect*> rects;
	float gravityTimer = 0;
	float interactionTimer = 0;
	const float _updateGravityTime, _updateInteractionTime;
	const bool patterns[5][8] = {
		{1,1,1,1,0,0,0,0},
	    {0,1,1,0,1,1,0,0},
	    {1,1,0,0,1,1,0,0},
	    {1,1,1,0,0,0,1,0},
		{1,1,1,0,0,1,0,0},
	};
	int _width;
	void Rotate();
public:
	Part(Part&);
	std::vector<Rect*>& getRects();
	Part(int x, int y, int width, float updateGravityTime, float updateInteractionTime);
	Part* UpdateGravity(float dt, float boost);
	Part* UpdateInteraction(float dt, int dx, bool toRotate);
	void Draw(HDC& hdc);
	void Clear(HDC& hdc);
};

