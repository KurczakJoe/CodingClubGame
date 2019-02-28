#ifndef COMMMON_H
#define COMMMON_H

#include <vector>

enum KeyPressed {
	KeyOther = 0,
	KeyUp,
	KeyDown,
	KeyLeft,
	KeyRight,
	KeyExit
};

struct Status {
	int score, health, power;
	std::vector<const char *> enemy_name;
	std::vector<int> enemy_score;
	const char *winner_name;
};

struct Summary {
};


#endif

