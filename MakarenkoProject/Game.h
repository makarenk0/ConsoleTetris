#pragma once
#include <ctime>
#include "GameState.h"

class Game
{
private:
	bool _exit = false;
	GameState _gstate;
public:
	Game(int width, int height);
	void run();
};

