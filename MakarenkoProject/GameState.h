#pragma once

#include "Part.h"
#include "Map.h"

class GameState
{
public:
	GameState(int width, int height);
	void Draw(float interpolation);
	void Update(float dt);
	void HandleInput();
	int dx = 0;
	void cls();
private:
	HWND hwnd;
	HDC hdc;
	Map* map;
	Part* movingPart;
};

