#include <ncurses.h>
#include "Console.h"



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

void Console::PrintScore(Status status) {
	printw("======================\n");
	printw("Your status: %d\n", status.score);
	printw("Your hp: %d  Your power:%d\n", status.health, status.power);
	printw("======================\n");
	for(int i = 0; i < status.enemy_name.size(); i++)
		printw("%s status: %d, \n", status.enemy_name[i], status.enemy_score[i]);
	printw("======================\n");
	refresh();
}

void Console::PrintEndGame(Status status) {
	printw("======================\n");
	printw("Game over!\n");
	printw("The winner is: %s\n", status.winner_name);
	printw("======================\n");
	refresh();
}

