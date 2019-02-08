#include <time.h>
#include "Console.h"
#include "Map.h"
#include "Game.h"

Console console;
Map map;

int main() {
	srand(time(NULL));
	while(gamerunning) {
		console.ClearScreen();
		map.DrawMap();
		
		console.PrintScore();
		
		if(map.CountDots() == 0) {
			console.PrintEndGame();
			gamerunning = false;
		} 
		
		system("pause>nul");
		console.HandleInput();
		console.EnemiesInput();
	}
}