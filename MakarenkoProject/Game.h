#pragma once
#include <ctime>
#include "GameState.h"

class Game
{
private:
	GameState _gstate;
public:
	Game(int width, int height, int tileWidth);
	void run();
};

