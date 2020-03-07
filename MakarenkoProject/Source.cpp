#include <windows.h>
#include <iostream>
#include <cmath>
#include "Game.h"

int main() {
	/*HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	SetPixel(hdc, 10, 50, RGB(255, 255, 255));
	Rectangle(hdc, 20, 20, 50, 50);*/
	Game game(20, 20);
	game.run();

	std::cin.get();
	return 0;
}