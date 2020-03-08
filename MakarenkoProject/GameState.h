#pragma once

#include "Part.h"
#include "Map.h"

class GameState
{
public:
	GameState(int width, int height, int tileWidth);
	void Draw(float interpolation);
	void Update(float dt);
	void HandleInput();
	int dx = 0;
	void cls();
	bool _exit = false;
private:
	HWND hwnd;
	HDC hdc;
	Map* map;
	Part* movingPart;
	const int xWindow = 20, yWindow = 20;
	int _width, _height, _tileWidth;
	bool _toRotate = false;
	int partsCounter = 0;
	float gameSpeed = 0.4;
	float _boost = 1;
	void gameOver();
};

