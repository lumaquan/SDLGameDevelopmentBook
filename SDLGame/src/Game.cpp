#include "Game.h"
#include<SDL.h>
#include<SDL_image.h>


int spritesheet_width = 0;
int spritesheet_high = 0;

Game::Game() :m_bRunning{}, m_pWindow{}, m_pRenderer{}, m_currentFrame{0}
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (m_pWindow != 0)
		{

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			m_textureManager.load("assets/animate-alpha.png","animate", m_pRenderer);
			m_bRunning = true;
		}
		else
		{
			m_bRunning = false;
		}
	}
	else
	{
		m_bRunning = false;
	}

	return m_bRunning;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_textureManager.draw("animate", 0, 0, 128, 82,m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
	m_textureManager.drawFrame("animate", 100, 100, 128, 82,1, m_currentFrame, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::running()
{
	return m_bRunning;
}