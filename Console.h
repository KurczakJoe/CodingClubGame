#ifndef CONSOLE_H
#define CONSOLE_H
#include "Player.h"
#include "Game.h"
#include "Map.h"
#pragma once

class Console {
public:
	Console();
	~Console();
        void Init();
	void ClearScreen();
	void HandleInput(Game &game, Map &map);
	void DrawMap(Map &map);
	void PrintScore(Game &game);
	void PrintEndGame(Game &game);
};


#endif
