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

	int getW() { return xSize; }
	int getH() { return ySize; }

	// x,y variants
	bool is_empty(int x, int y) { return mapTable[y][x] == ' '; }
	bool is_dot(int x, int y) { return mapTable[y][x] == '.'; }
	void set(int x, int y, char box) { mapTable[y][x] = box; }
	char *get_row(int y) { return mapTable[y]; }

	// Point variants
	bool is_empty(Point pt) { return is_empty(pt.x, pt.y); }
	bool is_dot(Point pt) { return is_dot(pt.x, pt.y); }
	void set(Point pt, char box) { set(pt.x, pt.y, box); }

private:
	int xSize;
	int ySize;
	char mapTable[10][11]; // Note: [Y][X]
};


#endif
