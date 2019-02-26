#include <time.h>
#include "Common.h"
#include "Console.h"
#include "Map.h"
#include "Game.h"

/*

       .--> Common <------.
       | .--> Map <------.|
	   ||       ^        ||
	   ||       |        ||
       ||      Player <-.||
       ||               |||
    Console             Game
       ^                 ^
       |                 |
        `-----Main ------'
*/

Console console;
Map map;
Game game(map);

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
		
		KeyPressed key = console.getKey();
		game.HandleInput(map, key);
		game.EnemiesInput(map);
	}
}
