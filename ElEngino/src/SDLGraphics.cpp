#include "SDLGraphics.h"
#include "SDL_image.h"
#include "Color.h"
#include <SDL.h>
#include <iostream>
using namespace engino;



engino::SDLGraphics::SDLGraphics()
{


	
}

engino::SDLGraphics::~SDLGraphics()
{
	TTF_Quit();
}

void engino::SDLGraphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
}

void engino::SDLGraphics::Clear()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
}

void engino::SDLGraphics::Present()
{
	SDL_RenderPresent(renderer);
}

bool engino::SDLGraphics::Initialize(const char* name, int w, int h)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		return false;
	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_TOOLTIP;
	Window = SDL_CreateWindow(name, _x, _y, w, h, _flag);

	_flag = SDL_RENDERER_ACCELERATED;
	renderer = SDL_CreateRenderer(Window, -1, _flag);
	TTF_Init();
	if (!Window)
	{
		return false;
	}
	if (!renderer) {
		return false;
	}

	return true; 
}

void engino::SDLGraphics::Drawline(float x1, float y1, float x2, float y2)
{
	SDL_RenderDrawLine(renderer, x1,y1,x2,y2);
}

void engino::SDLGraphics::DrawRect(int x, int y, int w, int h)
{
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = y;
	get_rect.h = 100;
	get_rect.w = 100;

	SDL_RenderDrawRect(renderer, &get_rect);
}

void engino::SDLGraphics::FillRect(int x, int y, int w, int h)
{
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = y;
	get_rect.h = 100;
	get_rect.w = 100;

	SDL_RenderFillRect(renderer, &get_rect);
}

size_t engino::SDLGraphics::LoadTexture(const char* filename)
{
	const size_t textureId = std::hash<std::string>()(filename);

	if (hashMap.find(textureId) != hashMap.end()) {
		return textureId;
	}

	SDL_Texture* loadedTexture = IMG_LoadTexture(renderer, filename);
	if (loadedTexture != nullptr) {
		hashMap[textureId] = loadedTexture;
		return textureId;
	}
}

size_t engino::SDLGraphics::LoadFont(const char* filename, int fileSize)
{
	const size_t fontId = std::hash<std::string>()(filename);

	if (FontHash.find(fontId) != FontHash.end()) {
		return fontId;
	}
	TTF_Font* _font = TTF_OpenFont(filename, fileSize);
	if (_font != nullptr) {
		FontHash[fontId] = _font;
		return fontId;
	}
}

void engino::SDLGraphics::DrawSprite(int x, int y, int w, int h, int angle, size_t fileId) {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect* image = new SDL_Rect();
	image->w = w;
	image->h = h;

	SDL_Rect* pos = new SDL_Rect();
	pos->x = x;
	pos->y = y;
	pos->w = 100;
	pos->h = 100;

	SDL_RenderCopy(renderer, hashMap[fileId], image, pos);
}


SDL_Texture* g_TextureBuffer;
void engino::SDLGraphics::DrawFont(int x, int y, int w, int h, size_t fontId, const char* text, const Color& color)
{
	if (FontHash.count(fontId) > 0)
	{
		SDL_Color _color = { color.red, color.green, color.blue, color.alpha };
		TTF_Font* _font = FontHash[fontId];

		SDL_Rect* pos = new SDL_Rect();
		pos->x = x;
		pos->y = y;
		TTF_SizeText(_font, text, &pos->w,&pos->h);
		

		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text, _color);
		g_TextureBuffer = SDL_CreateTextureFromSurface(renderer, _surface);
		SDL_RenderCopy(renderer, g_TextureBuffer, nullptr, pos);
		SDL_FreeSurface(_surface);
	}

}
