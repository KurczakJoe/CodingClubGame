#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Point.h"
#include "Map.h"
#pragma once

class Player {
public:
	Player(Map &map, Point loc, char av, int pow, std::string name);
	~Player();
	void Move(Map &map, Point point);
	char findDirToOpponent(Player *player);
	void attack(Player *player);

	Point playerLoc;
	std::string playerName;
	char avatar;
	int score;
	char dir;
	int health;
	int power;
};

#endif
