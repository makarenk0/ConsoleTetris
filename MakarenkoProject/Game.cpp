#include "Game.h"




Game::Game(int width, int height, int tileWidth) : _gstate(GameState(width, height, tileWidth))
{
	
}

void Game::run()
{
	float newTime, frameTime, interpolation;
	const float dt = 1.0f / 10.0f;
	float currentTime = clock() / CLOCKS_PER_SEC;
	float accumulator = 0.0f;
	while (!_gstate._exit) {
		newTime = clock()*1.0 / CLOCKS_PER_SEC;
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
			_gstate.Update(dt);
			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		_gstate.Draw(interpolation);
	}
}
