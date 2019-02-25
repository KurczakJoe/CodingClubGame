#include <iostream>
#include "Console.h"
#include "Player.h"
#include "Game.h"
#include <windows.h>

bool gamerunning = true;

Console::Console() {
	Game game;
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

void Console::HandleInput() {
	system("pause>nul");
	if(GetAsyncKeyState(VK_UP)) game.player->Move({-1, 0});
	if(GetAsyncKeyState(VK_DOWN)) game.player->Move({1, 0});
	if(GetAsyncKeyState(VK_RIGHT)) game.player->Move({0, 1});
	if(GetAsyncKeyState(VK_LEFT)) game.player->Move({0, -1});
	if(GetAsyncKeyState(VK_ESCAPE)) gamerunning = false;
}

void Console::EnemiesInput() {
	for(Player *enemy : game.enemies) {
		char dir = enemy->findDirToOpponent(game.player);
		if(dir == 'U') enemy->Move({-1, 0});
		if(dir == 'R') enemy->Move({0, 1});
		if(dir == 'D') enemy->Move({1, 0});
		if(dir == 'L') enemy->Move({0, -1});
	}
}

void Console::PrintScore() {
	std::cout << "======================" << std::endl;
	std::cout << "Your score:     " << game.player->score << std::endl;
	std::cout << "Your hp: " << game.player->health << "    Your power: " << game.player->power << "    " << std::endl;
	std::cout << "======================" << std::endl;
	for(int i = 0; i < game.enemies.size(); i++)
		std::cout << game.enemies[i]->playerName << " score: " << game.enemies[i]->score << std::endl;
	std::cout << "======================" << std::endl;
}

void Console::PrintEndGame() {
	std::cout << "======================" << std::endl;
	std::cout << "Game over!" << std::endl;
	Player winner = game.getWinner();
	std::cout << "The winner is: " << winner.playerName << std::endl;
	std::cout << "======================" << std::endl;
}
