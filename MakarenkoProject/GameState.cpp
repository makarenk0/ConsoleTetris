#include "GameState.h"
#include <iostream>

GameState::GameState(int width, int height)
{
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
    movingPart = new Part(40, 20, 20, 0.5);
    map = new Map(20, 20, 500, 200, 20, movingPart);
}

void GameState::Draw(float interpolation)
{
    cls();
    map->Draw(hdc);
    movingPart->Draw(hdc);
}

void GameState::Update(float dt)
{
    HandleInput();
    if (map->Update()) {
        
        delete movingPart;
        movingPart = new Part(40, 40, 20, 0.5);
    }
    movingPart->Update(dt, dx);
}

void GameState::HandleInput()
{
    dx = 0;
    if (GetAsyncKeyState(VK_LEFT)&&map->canMove(-20, 0)) {
        dx = -20;
    }
    if (GetAsyncKeyState(VK_RIGHT) && map->canMove(20, 0)) {
        dx = 20;
    }
}

void GameState::cls()
{
    InvalidateRect(hwnd, NULL, true);
}
