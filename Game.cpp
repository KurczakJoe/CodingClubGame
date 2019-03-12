#include "Game.h"
#include "Player.h"

Game::Game() {
	running = true;
	player = new Player(map, {1,1},'@', 4, "Ania");
	this->enemies.push_back(new Player(map, {8,8},'$', 3, "Enemy1"));
	this->enemies.push_back(new Player(map, {1,8},'$', 3, "Enemy2"));
	this->enemies.push_back(new Player(map, {8,1},'$', 3, "Enemy3"));
}

Game::~Game() {
	
}

void Game::HandleInput(KeyPressed key) {
	switch (key) {
		case KeyUp:    player->Move(map, {0, -1}); break;
		case KeyDown:  player->Move(map, {0, 1}); break;
		case KeyRight: player->Move(map, {1, 0}); break;
		case KeyLeft:  player->Move(map, {-1, 0}); break;
		case KeyExit: running = false; break;
	}
		
	if(map.CountDots() == 0) {
		running = false;
	} 
}

void Game::EnemiesInput() {
	for(Player *enemy : enemies) {
		char dir = enemy->findDirToOpponent(player);
		if(dir == 'U') enemy->Move(map, { 0, -1});
		if(dir == 'R') enemy->Move(map, { 1,  0});
		if(dir == 'D') enemy->Move(map, { 0,  1});
		if(dir == 'L') enemy->Move(map, {-1,  0});
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

Status Game::getStatus()
{
	Status status;
	
	status.score = player->score;
	status.health = player->health;
	status.power = player->power;
	
	for(int i = 0; i < enemies.size(); i++)
	{
		status.enemy_name.push_back(enemies[i]->playerName.c_str());
		status.enemy_score.push_back(enemies[i]->score);
	}

	status.winner_name = running ? "" : getWinner().playerName.c_str();

	return status;
}

