#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "vector"
#pragma once

class Game {
public:
	Game();
	~Game();
	void pushEnemiesToVector();
	Player getWinner();
	bool running;
	Player* player;
	Player* enemy1;
	Player* enemy2;
	Player* enemy3;
	std::vector<Player*> enemies;
};

#endif
