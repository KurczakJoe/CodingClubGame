#ifndef CONSOLE_H
#define CONSOLE_H
#include "Common.h"
#include "Map.h"
#pragma once

class Console {
public:
	Console();
	~Console();
	void Init();
	void ClearScreen();
	void DrawMap(Map &map);
	void PrintScore(Status score);
	void PrintEndGame(Status summary);
	KeyPressed getKey();
};


#endif
