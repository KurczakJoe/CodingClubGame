#include <iostream>
#include "Console.h"
#include "Player.h"
#include "Game.h"
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
	for(int i = 0; i < map.xSize; i++) {
		std::cout << map.mapTable[i] << std::endl;
	}
}

void Console::PrintScore(Game &game) {
	std::cout << "======================" << std::endl;
	std::cout << "Your score:     " << game.player->score << std::endl;
	std::cout << "Your hp: " << game.player->health << "    Your power: " << game.player->power << "    " << std::endl;
	std::cout << "======================" << std::endl;
	for(int i = 0; i < game.enemies.size(); i++)
		std::cout << game.enemies[i]->playerName << " score: " << game.enemies[i]->score << std::endl;
	std::cout << "======================" << std::endl;
}

void Console::PrintEndGame(Game &game) {
	std::cout << "======================" << std::endl;
	std::cout << "Game over!" << std::endl;
	Player winner = game.getWinner();
	std::cout << "The winner is: " << winner.playerName << std::endl;
	std::cout << "======================" << std::endl;
}
