#ifndef CONSOLE_H
#define CONSOLE_H
#include "Common.h"
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
	void DrawMap(Map &map);
	void PrintScore(Game &game);
	void PrintEndGame(Game &game);
	KeyPressed getKey();
};


#endif
