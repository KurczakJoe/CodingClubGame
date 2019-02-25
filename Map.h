#ifndef MAP_H
#define MAP_H
#pragma once
#include "Point.h"
#include "Console.h"

class Map {
public:
	Map();
	~Map();
	void PlaceDots();
	int CountDots();
	void DrawMap(Console &console);
};

extern const int xSize;
extern const int ySize;
extern char mapTable[10][11];

#endif
