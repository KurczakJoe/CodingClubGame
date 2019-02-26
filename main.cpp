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
Game game;

int main() {
	console.Init();
	srand(time(NULL));
	while(game.running) {
		console.ClearScreen();
		console.DrawMap(game.map);
		console.PrintScore(game);
		
		if(game.map.CountDots() == 0) {
			console.PrintEndGame(game);
			game.running = false;
		} 
		
		KeyPressed key = console.getKey();
		game.HandleInput(key);
		game.EnemiesInput();
	}
}
