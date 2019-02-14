#ifndef CONSOLE_H
#define CONSOLE_H
#include "Player.h"
#include "Game.h"
#pragma once

class Console {
public:
	Console();
	~Console();
	void ClearScreen();
	void GetInput();
	void EnemiesInput();
	void PrintScore();
	void PrintEndGame();
	Game game;
};

extern bool gamerunning;

#endif
