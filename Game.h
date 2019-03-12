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
	std::vector<Player*> enemies;
};

#endif
