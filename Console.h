#ifndef CONSOLE_H
#define CONSOLE_H
#include "Player.h"
#include "Game.h"
#pragma once

class Console {
public:
	Console();
	~Console();
        void Init();
	void ClearScreen();
	void HandleInput();
	void EnemiesInput();
	void PrintScore();
	void PrintEndGame();
	Game game;
};


#endif
