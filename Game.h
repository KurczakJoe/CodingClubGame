#ifndef GAME_H
#define GAME_H
#include "Common.h"
#include "Player.h"
#include "vector"
#pragma once

class Game {
public:
	Game(Map &map);
	~Game();
	void HandleInput(Map &map, KeyPressed key);
	void pushEnemiesToVector();
	void EnemiesInput(Map &map);
	Player getWinner();
	bool running;
	Player* player;
	Player* enemy1;
	Player* enemy2;
	Player* enemy3;
	std::vector<Player*> enemies;
};

#endif
