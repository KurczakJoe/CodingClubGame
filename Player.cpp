#include "Player.h"
#include "Map.h"
#include "Point.h"

Player::Player(Point loc, char av, int pow, std::string name) {
	playerName = name;
	playerLoc = loc;
	avatar = av;
	mapTable[loc.x][loc.y] = avatar;
	score = 0;
	health = 100;
	power = pow;
}

Player::~Player() {
	
}

void Player::Move(Point point) {
	Point pOld = this->playerLoc;
	Point pNew = pOld + point;

	if(mapTable[pNew.x][pNew.y] == ' ' || mapTable[pNew.x][pNew.y] == '.') {
		if(mapTable[pNew.x][pNew.y] == '.') this->score++;
		mapTable[pOld.x][pOld.y] = ' ';
		mapTable[pNew.x][pNew.y] = this->avatar;
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