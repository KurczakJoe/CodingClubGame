#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Point.h"
#pragma once

class Player {
public:
	Player(Point loc, char av, int pow, std::string name);
	~Player();	
	void Move(Point point);
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