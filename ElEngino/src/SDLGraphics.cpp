#include "SDLGraphics.h"
#include "SDL_image.h"
#include "Color.h"
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
using namespace engino;


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


void engino::SDLGraphics::Drawline(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1,y1,x2,y2);
}

#pragma region

void engino::SDLGraphics::DrawRect(int x, int y, int w, int h)
{
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = y;
	get_rect.h = 100;
	get_rect.w = 100;

	SDL_RenderDrawRect(renderer, &get_rect);
}


void engino::SDLGraphics::DrawRect(const RectI& rect, const Color& color)
{
	SDL_Rect get_rect = { 0 };
	get_rect.x = rect.x;
	get_rect.y = rect.y;
	get_rect.h = rect.h;
	get_rect.w = rect.w;

	SetColor(color);

	SDL_RenderDrawRect(renderer, &get_rect);
}
#pragma endregion DrawRect

#pragma region

void engino::SDLGraphics::FillRect(int x, int y, int w, int h)
{
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = y;
	get_rect.h = 100;
	get_rect.w = 100;

	SDL_RenderFillRect(renderer, &get_rect);
}


void engino::SDLGraphics::FillRect(const RectF& rect, const Color& color)
{
	SDL_Rect get_rect = { 0 };
	get_rect.x = rect.x;
	get_rect.y = rect.y;
	get_rect.h = rect.h;
	get_rect.w = rect.w;

	SetColor(color);

	SDL_RenderFillRect(renderer, &get_rect);
}
#pragma endregion FillRect

#pragma region 


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


size_t engino::SDLGraphics::LoadFont(const char* filename, float fileSize)
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

#pragma endregion Loads

#pragma region


void engino::SDLGraphics::DrawSprite(int x, int y, int w, int h, double angle, size_t fileId) {

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	RectI image = RectI();
	image.w = w;
	image.h = h;

	RectI pos = RectI();
	pos.x = x;
	pos.y = y;
	pos.w = 100;
	pos.h = 100;

	//SDL_RenderCopy(renderer, hashMap[fileId], &image, &pos);
	Flip f = { 0 };
	DrawSprite(image, pos, 0, f, Color(255, 255, 255, 255), fileId);
}

void engino::SDLGraphics::DrawSprite(const RectI& src, const RectI& dst, double angle, const Flip& flip, const Color& color, size_t fileId)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect image = { 0 };
	image.w = src.w;
	image.h = src.h;
	image.x = src.x;
	image.y = src.y;

	SDL_Rect pos = {0};
	pos.x = dst.x;
	pos.y = dst.y;
	pos.w = dst.w;
	pos.h = dst.h;

	SDL_RenderCopy(renderer, hashMap[fileId], &image, &pos);
}
void engino::SDLGraphics::DrawSprite(const RectF& dst, const Color& color, size_t fileId)
{
}

void engino::SDLGraphics::DrawSprite(const Color& color, size_t fileId)
{
}
#pragma endregion DrawSprite

#pragma region

void engino::SDLGraphics::GetTextureSize(int* w, int* h, size_t id)
{
	if (hashMap.count(id) > 0)
	{
		SDL_QueryTexture(hashMap[id], nullptr, nullptr, w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}
}

void engino::SDLGraphics::GetTextSize(const char* text, size_t fontId, int* w, int* h)
{
	if (FontHash.count(fontId) > 0)
	{
		TTF_SizeText(FontHash[fontId], text, w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}
}


#pragma endregion GetSizes

SDL_Texture* g_TextureBuffer;
/// <summary>
/// draws text on the screen
/// </summary>
/// <param name="x">the x</param>
/// <param name="y">the y</param>
/// <param name="w">the width</param>
/// <param name="h">the height</param>
/// <param name="fontId">the font's id aquired through loadFont</param>
/// <param name="text">the text to display</param>
/// <param name="color">the color of the text</param>
/// <param name="scale">how big to scale.</param>
void engino::SDLGraphics::DrawFont(int x, int y, int w, int h, size_t fontId, const char* text, const Color& color, float scale)
{

	if (FontHash.count(fontId) > 0)
	{
		SDL_Color _color = { color.red, color.green, color.blue, color.alpha };
		TTF_Font* _font = FontHash[fontId];

		SDL_Rect pos = {0};
		pos.x = x;
		pos.y = y;
		TTF_SizeText(_font, text, &pos.w,&pos.h);
		pos.w *= scale;
		pos.h *= scale;

		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text, _color);
		g_TextureBuffer = SDL_CreateTextureFromSurface(renderer, _surface);
		SDL_RenderCopy(renderer, g_TextureBuffer, nullptr, &pos);
		SDL_FreeSurface(_surface);
	}
}

void engino::SDLGraphics::Exit() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(Window);
}
