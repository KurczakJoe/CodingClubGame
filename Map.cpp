#include <stdlib.h>
#include "Map.h"

Map::Map() {
	xSize = 10;
	ySize = 10;

	// frame
	for (int x=0; x<xSize; x++)
		for (int y=0; y<ySize; y++)
			mapTable[x][y] = (x==0 || y==0 || x==xSize-1 || y==ySize-1) ? '#' : ' ';
	
	this->PlaceDots();
}

Map::~Map() {
	
}

void Map::PlaceDots() {
	for(int i = 0; i < xSize; i++) {
		for(int j = 0; j < ySize; j++) {
			int tmp;
			tmp = (mapTable[i][j] == ' ') ? rand() % 2 : 0;
			if(tmp) mapTable[i][j] = '.';
		}
	}
}

int Map::CountDots() {
	int dots = 0;
	for(int i = 0; i < xSize; i++) {
		for(int j = 0; j < ySize; j++) {
			if(mapTable[i][j] == '.') dots++;
		}
	}
	return dots;
}


