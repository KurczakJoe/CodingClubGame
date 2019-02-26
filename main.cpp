#include <time.h>
#include "Console.h"
#include "Map.h"
#include "Game.h"

/*

       .--> Map <---------.
       |.-->  Stats <----.|
       ||      Player <-.||
       ||               |||
    Console             Game
       ^                 ^
       |                 |
        `-----Main ------'
*/

Game game;
Console console;
Map map;

int main() {
	console.Init();
	srand(time(NULL));
	while(game.running) {
		console.ClearScreen();
		console.DrawMap(map);
		
		console.PrintScore(game);
		
		if(map.CountDots() == 0) {
			console.PrintEndGame(game);
			game.running = false;
		} 
		
		console.HandleInput(game);
		game.EnemiesInput();
	}
}
