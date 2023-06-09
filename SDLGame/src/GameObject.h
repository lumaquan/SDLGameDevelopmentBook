#pragma once
#include <SDL.h>
#include <iostream>

class GameObject
{
public:
	
	void update();
	
	void clean();

	void load(int x, int y, int width, int height, std::string textureID);

	void draw(SDL_Renderer* pRenderer);


protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};