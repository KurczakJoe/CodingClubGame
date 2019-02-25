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

Console console;
Map map;

int main() {
	console.Init();
	srand(time(NULL));
	while(console.game.running) {
		console.ClearScreen();
		map.DrawMap(console);
		
		console.PrintScore();
		
		if(map.CountDots() == 0) {
			console.PrintEndGame();
			console.game.running = false;
		} 
		
		console.HandleInput();
		console.EnemiesInput();
	}
}
