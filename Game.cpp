#include "Game.h"
#include "Player.h"

Game::Game() {
	running = true;
	player = new Player({1,1},'@', 4, "Ania");
	enemy1 = new Player({8,8},'$', 3, "Enemy1");
	enemy2 = new Player({1,8},'$', 3, "Enemy2");
	enemy3 = new Player({8,1},'$', 3, "Enemy3");
	pushEnemiesToVector();
}

Game::~Game() {
	
}

void Game::pushEnemiesToVector() {
	this->enemies.push_back(this->enemy1);
	this->enemies.push_back(this->enemy2);
	this->enemies.push_back(this->enemy3);
}

void Game::EnemiesInput() {
	for(Player *enemy : enemies) {
		char dir = enemy->findDirToOpponent(player);
		if(dir == 'U') enemy->Move({-1, 0});
		if(dir == 'R') enemy->Move({0, 1});
		if(dir == 'D') enemy->Move({1, 0});
		if(dir == 'L') enemy->Move({0, -1});
	}
}

Player Game::getWinner() {
	Player *winner = this->player;
	int maxScore = this->player->score;
	for(int i = 0; i < enemies.size(); i++)
		if (enemies[i]->score > maxScore) {
			maxScore = enemies[i]->score;
			winner = enemies[i];
		}
	return *winner;
}
