#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "TextureManager.h"

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
	TextureManager m_textureManager;
};


#endif // !GAME_H
