#include <iostream>
#include <ncurses.h>
#include "Console.h"
#include "Player.h"
#include "Game.h"



Console::Console() {
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

KeyPressed Console::getKey() {
	int key = getch();
	if(key == KEY_UP) return KeyUp;
	if(key == KEY_DOWN) return KeyDown;
	if(key == KEY_RIGHT) return KeyRight;
	if(key == KEY_LEFT) return KeyLeft;
	if(key == KEY_EXIT) return KeyExit;
	return KeyOther;
}

void Console::DrawMap(Map &map) {
	ClearScreen();
	for(int i = 0; i < map.xSize; i++) {
		mvprintw(i, 0, map.mapTable[i]);
	}
	refresh();
}

void Console::PrintScore(Game &game) {
	printw("======================\n");
	printw("Your score: %d\n", game.player->score);
	printw("Your hp: %d  Your power:%d\n", game.player->health, game.player->power);
	printw("======================\n");
	for(int i = 0; i < game.enemies.size(); i++)
		printw("%s score: %d, \n", game.enemies[i]->playerName.c_str(), game.enemies[i]->score);
	printw("======================\n");
	refresh();
}

void Console::PrintEndGame(Game &game) {
	printw("======================\n");
	printw("Game over!\n");
	Player winner = game.getWinner();
	printw("The winner is: %s\n", winner.playerName.c_str());
	printw("======================\n");
	refresh();
}
