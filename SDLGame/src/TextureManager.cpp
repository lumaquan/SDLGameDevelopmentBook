#include "TextureManager.h"
#include <SDL.h>
#include <SDL_image.h>


bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{

	SDL_Surface* surface = IMG_Load(fileName.c_str());

	if (!surface)
	{
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, surface);

	SDL_FreeSurface(surface);

	if (texture)
	{
		m_textureMap[id] = texture;
		return true;
	}

	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
