#include "GameState.h"
#include <iostream>


GameState::GameState(int width, int height, int tileWidth) : _width(width), _height(height), _tileWidth(tileWidth)
{
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
    
    
    map = new Map(xWindow, yWindow, width+ xWindow, height+ yWindow, tileWidth);
    map->Draw(hdc);
    movingPart = new Part(xWindow + tileWidth * ((_width / tileWidth) / 2), yWindow, tileWidth, gameSpeed, 0.1);
    map->printScore();
}

void GameState::Draw(float interpolation)
{
    movingPart->Draw(hdc);
    map->Draw(hdc);
}

void GameState::Update(float dt)
{
    HandleInput();

    Part* ig = movingPart->UpdateInteraction(dt, dx, _toRotate);
    if (ig != nullptr) {
        _toRotate = false;
        ig->Clear(hdc); //clear only part from previous frame 
        delete ig;
    }

    if (map->Update(movingPart)) {
        cls();   //clear whole screen
        map->printScore();
        delete movingPart;
        ++partsCounter;
        if (partsCounter % 10 == 0 && gameSpeed > 0.09) gameSpeed -= 0.05;   //incresing speed to to make game harder
        movingPart = new Part(xWindow + _tileWidth*((_width / _tileWidth)/2), yWindow, _tileWidth, gameSpeed, 0.1);
        if (!map->canMove(0, 0, movingPart)) gameOver();
    }

    Part* pg = movingPart->UpdateGravity(dt , _boost);
    if (pg!=nullptr) {
        pg->Clear(hdc); //clear only part from previous frame 
        delete pg;
    }
    _boost = 1;
   
    
}

void GameState::HandleInput()
{
    dx = 0;
    if (GetAsyncKeyState(VK_LEFT)&&map->canMove(-_tileWidth, 0, movingPart)) {
        dx = -_tileWidth;
    }
    if (GetAsyncKeyState(VK_RIGHT) && map->canMove(_tileWidth, 0, movingPart)) {
        dx = _tileWidth;
    }
    if (GetAsyncKeyState(VK_SPACE) && map->canRotate(movingPart)) {
        _toRotate = true;
    }
    if (GetAsyncKeyState(VK_DOWN)) {  // boosting speed in 3 times
        _boost = 3;
    }
}

void GameState::cls()
{
    InvalidateRect(hwnd, NULL, false);
}

void GameState::gameOver()
{
    cls();
    _exit = true;
    printf("\r%80c\r", ' ');
    std::cout << "Game over!";
}

