#include "Game.h"
#include "Player.h"

Game::Game() {
	running = true;
	player = new Player(map, {1,1},'@', 4, "Ania");
	enemy1 = new Player(map, {8,8},'$', 3, "Enemy1");
	enemy2 = new Player(map, {1,8},'$', 3, "Enemy2");
	enemy3 = new Player(map, {8,1},'$', 3, "Enemy3");
	pushEnemiesToVector();
}

Game::~Game() {
	
}

void Game::pushEnemiesToVector() {
	this->enemies.push_back(this->enemy1);
	this->enemies.push_back(this->enemy2);
	this->enemies.push_back(this->enemy3);
}

void Game::HandleInput(KeyPressed key) {
	switch (key) {
		case KeyUp:    player->Move(map, {-1, 0}); break;
		case KeyDown:  player->Move(map, {1, 0}); break;
		case KeyRight: player->Move(map, {0, 1}); break;
		case KeyLeft:  player->Move(map, {0, -1}); break;
		case KeyExit: running = false; break;
	}
}

void Game::EnemiesInput() {
	for(Player *enemy : enemies) {
		char dir = enemy->findDirToOpponent(player);
		if(dir == 'U') enemy->Move(map, {-1, 0});
		if(dir == 'R') enemy->Move(map, {0, 1});
		if(dir == 'D') enemy->Move(map, {1, 0});
		if(dir == 'L') enemy->Move(map, {0, -1});
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
