#pragma once

#include "Color.h"
struct SDL_Texture;

namespace engino {
	class IGraphics
	{
	public:
		virtual void SetColor(const Color& color) = 0;
		virtual void Clear() = 0;
		virtual void Present() = 0;
		virtual bool Initialize(const char* name, int w, int h)= 0;
		virtual void Drawline(float x1, float y1, float x2, float y2) = 0;
		virtual void DrawRect(int x, int y, int w, int h) = 0;
		virtual void FillRect(int x, int y, int w, int h) = 0;
		virtual size_t LoadTexture(const char* filename) = 0;
		virtual size_t LoadFont(const char* filename, int fileSize) = 0;
		virtual void DrawFont(int x, int y, int w, int h, size_t fontId, const char* text, const Color& color) = 0;
		virtual void DrawSprite(int x, int y, int w, int h, int angle, size_t fileId) = 0;
	};

}
