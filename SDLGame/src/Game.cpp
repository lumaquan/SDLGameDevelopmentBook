#include "Game.h"
#include<SDL.h>


int spritesheet_width = 0;
int spritesheet_high = 0;

Game::Game() :m_bRunning{}, m_pWindow{}, m_pRenderer{}, m_pTexture{}, m_sourceRectangle{}, m_destinationRectangle{}
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
			SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			SDL_FreeSurface(pTempSurface);
			SDL_QueryTexture(m_pTexture, NULL, NULL, &spritesheet_width, &spritesheet_high);
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
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_sourceRectangle.w = spritesheet_width / 6;
	m_sourceRectangle.h = spritesheet_high;
	m_sourceRectangle.x = spritesheet_width / 6 * int(((SDL_GetTicks() / 50) % 6));
	m_sourceRectangle.y = 0;

	m_destinationRectangle.w = spritesheet_width / 6;
	m_destinationRectangle.h = spritesheet_high;
	m_destinationRectangle.x = 0;
	m_destinationRectangle.y = 0;
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
