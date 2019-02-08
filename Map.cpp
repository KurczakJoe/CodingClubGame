#include <iostream>
#include "Map.h"

extern const int xSize = 10;
extern const int ySize = 10;

char mapTable[xSize][ySize+1] = {
	"##########",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"##########"};


Map::Map() {
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

void Map::DrawMap() {
	for(int i = 0; i < xSize; i++) {
		std::cout << mapTable[i] << std::endl;
	}
}