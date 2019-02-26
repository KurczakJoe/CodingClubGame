#include "Player.h"
#include "Map.h"
#include "Point.h"

Player::Player(Map &map, Point loc, char av, int pow, std::string name) {
	playerName = name;
	playerLoc = loc;
	avatar = av;
	map.mapTable[loc.x][loc.y] = avatar;
	score = 0;
	health = 100;
	power = pow;
}

Player::~Player() {
	
}

void Player::Move(Map &map, Point point) {
	Point pOld = this->playerLoc;
	Point pNew = pOld + point;

	if(map.mapTable[pNew.x][pNew.y] == ' ' || map.mapTable[pNew.x][pNew.y] == '.') {
		if(map.mapTable[pNew.x][pNew.y] == '.') this->score++;
		map.mapTable[pOld.x][pOld.y] = ' ';
		map.mapTable[pNew.x][pNew.y] = this->avatar;
		this->playerLoc = this->playerLoc + point;
	}
}

char Player::findDirToOpponent(Player *player) {
	int xDif = this->playerLoc.x - player->playerLoc.x;
	int yDif = this->playerLoc.y - player->playerLoc.y;
	if(xDif > 0) return 'U';
	if(xDif < 0) return 'D';
	if(yDif > 0) return 'L';
	if(yDif < 0) return 'R';
}

void Player::attack(Player *opponent) {
	this->health -= opponent->power;
	opponent->health -= this->power;
	if(this->health <= 0) this->avatar == ' ';
	if(opponent->health <= 0) opponent->avatar == ' ';
}
