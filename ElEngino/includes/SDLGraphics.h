#pragma once
#include "iGraphics.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "map"
namespace engino {

	class SDLGraphics final : public IGraphics
	{
	public:
		SDLGraphics();
		~SDLGraphics();
		virtual void SetColor(const Color& color) override;
		virtual void Clear() override;
		virtual void Present() override;
		virtual bool Initialize(const char* name, int w, int h) override;
		virtual void Drawline(float x1, float y1, float x2, float y2) override;
		virtual void DrawRect(int x, int y, int w, int h) override;
		virtual void FillRect(int x, int y, int w, int h) override;
		virtual size_t LoadTexture(const char* filename) override;
		virtual size_t LoadFont(const char* filename, int fileSize) override;
		virtual void DrawSprite(int x, int y, int w, int h, int angle, size_t fileId) override;
		virtual void DrawFont(int x, int y, int w, int h, size_t fontId, const char* text, const Color& color) override;


	private:
		SDL_Renderer* renderer;
		SDL_Window* Window;
		std::map<size_t, SDL_Texture*> hashMap;
		std::map<size_t, TTF_Font*> FontHash;
	};

}

