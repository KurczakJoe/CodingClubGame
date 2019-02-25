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
	void HandleInput(Game &game);
	void EnemiesInput(Game &game);
	void PrintScore(Game &game);
	void PrintEndGame(Game &game);
};


#endif
