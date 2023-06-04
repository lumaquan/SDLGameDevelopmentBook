#include<SDL.h>
#include <iostream>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int	height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

void render()
{
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[])
{
	if (init("Chapter 1: Setting up SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
	{
		g_bRunning = true;
		std::cout << "SDL initialized and Window created!" << std::endl;
	}
	else
	{
		g_bRunning = false;
		std::cout << "SDL not initialized or Window not created!" << std::endl;
	}

	while (g_bRunning)
	{
		render();
	}

	SDL_Quit();

	return 0;
}