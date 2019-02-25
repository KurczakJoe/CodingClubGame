#include <iostream>
#include <ncurses.h>
#include "Console.h"
#include "Player.h"
#include "Game.h"



Console::Console() {
	Game game;
}

Console::~Console() {
	
}

void Console::Init() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    refresh();
}

void Console::ClearScreen() {
    clear();
}

void Console::HandleInput() {
	int key = getch();
//        printw("(%d) up%d dn%d right%d left%d exit%d\n", key, key == KEY_UP,key == KEY_DOWN,key == KEY_RIGHT,key == KEY_LEFT,key == KEY_EXIT); getch(); refresh();
	if(key == KEY_UP) game.player->Move({-1, 0});
	if(key == KEY_DOWN) game.player->Move({1, 0});
	if(key == KEY_RIGHT) game.player->Move({0, 1});
	if(key == KEY_LEFT) game.player->Move({0, -1});
	if(key == KEY_EXIT) game.running = false;
}

void Console::EnemiesInput() {
	for(Player *enemy : game.enemies) {
		char dir = enemy->findDirToOpponent(game.player);
		if(dir == 'U') enemy->Move({-1, 0});
		if(dir == 'R') enemy->Move({0, 1});
		if(dir == 'D') enemy->Move({1, 0});
		if(dir == 'L') enemy->Move({0, -1});
	}
}

void Console::PrintScore() {
	printw("======================\n");
	printw("Your score: %d\n", game.player->score);
	printw("Your hp: %d  Your power:%d\n", game.player->health, game.player->power);
	printw("======================\n");
	for(int i = 0; i < game.enemies.size(); i++)
		printw("%s score: %d, \n", game.enemies[i]->playerName.c_str(), game.enemies[i]->score);
	printw("======================\n");
	refresh();
}

void Console::PrintEndGame() {
	printw("======================\n");
	printw("Game over!\n");
	Player winner = game.getWinner();
	printw("The winner is: %s\n", winner.playerName.c_str());
	printw("======================\n");
	refresh();
}
