#ifndef MAP_H
#define MAP_H
#pragma once
#include "Point.h"

class Map {
public:
	Map();
	~Map();
	void PlaceDots();
	int CountDots();

	int xSize;
	int ySize;
	char mapTable[10][11];
};


#endif
