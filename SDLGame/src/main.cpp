#include<SDL.h>
#include <iostream>
#include "Game.h"

Game* game;

int main(int argc, char* args[])
{
	game = new Game();

	if (game->init("Chapter 1: Setting up SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480, false))
	{
		std::cout << "SDL initialized and Window created!" << std::endl;
	}
	else
	{
		std::cout << "SDL not initialized or Window not created!" << std::endl;
	}

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();

	return 0;
}