#include <iostream>
#include "Console.h"
#include <windows.h>

Console::Console() {
}

Console::~Console() {
	
}

void Console::Init() {
}

void Console::ClearScreen() {
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

KeyPressed Console::getKey() {
	system("pause>nul");
	if(GetAsyncKeyState(VK_UP)) return KeyUp;
	if(GetAsyncKeyState(VK_DOWN)) return KeyDown;
	if(GetAsyncKeyState(VK_RIGHT)) return KeyRight;
	if(GetAsyncKeyState(VK_LEFT)) return KeyLeft;
	if(GetAsyncKeyState(VK_ESCAPE)) return KeyExit;
	return KeyOther;
}

void Console::DrawMap(Map &map) {
	ClearScreen();
	for(int y = 0; y < map.getH(); y++) {
		std::cout << map.get_row(y) << std::endl;
	}
}

void Console::PrintScore(Status status) {
	std::cout << "======================" << std::endl;
	std::cout << "Your score:     " << status.score << std::endl;
	std::cout << "Your hp: " << status.health << "    Your power: " << status.power << "    " << std::endl;
	std::cout << "======================" << std::endl;
	for(int i = 0; i < game.enemy_name.size(); i++)
		std::cout << status.enemy_name[i] << " score: " << status.enemy_score[i] << std::endl;
	std::cout << "======================" << std::endl;
}

void Console::PrintEndGame(Status summary) {
	std::cout << "======================" << std::endl;
	std::cout << "Game over!" << std::endl;
	std::cout << "The winner is: " << summary.winner_name << std::endl;
	std::cout << "======================" << std::endl;
}
