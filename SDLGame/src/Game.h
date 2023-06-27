#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"



class Game
{
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int	height, int width, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();

private:
	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;

	GameObject m_go;
	Player m_player;

};
#endif // !GAME_H
