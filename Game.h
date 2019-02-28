#ifndef GAME_H
#define GAME_H
#include "Common.h"
#include "Player.h"
#include "Map.h"
#include "vector"
#pragma once

class Game {
public:
	Game();
	~Game();
	void HandleInput(KeyPressed key);
	void pushEnemiesToVector();
	void EnemiesInput();
	Player getWinner();
	Status getStatus();
	
	bool running;
	Map map;
	Player* player;
	Player* enemy1;
	Player* enemy2;
	Player* enemy3;
	std::vector<Player*> enemies;
};

#endif
