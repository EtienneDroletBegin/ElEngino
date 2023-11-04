#pragma once

#include "Color.h"
struct SDL_Texture;

struct RectI
{
	int x;
	int y;
	int w;
	int h;
};

struct RectF
{
	float x;
	float y;
	float w;
	float h;
};

struct Flip
{
	bool h;
	bool v;
};



namespace engino {
	class IGraphics
	{
	public:
		virtual void SetColor(const Color& color) = 0;
		virtual void Clear() = 0;
		virtual void Present() = 0;
		virtual bool Initialize(const char* name, int w, int h)= 0;

		virtual void DrawRect(int x, int y, int w, int h) = 0;
		virtual void DrawRect(const RectF& rect, const Color& color) = 0;

		virtual void FillRect(int x, int y, int w, int h) = 0;
		virtual void FillRect(const RectF& rect, const Color& color) = 0;

		virtual void Drawline(float x1, float y1, float x2, float y2) = 0;

		virtual size_t LoadTexture(const char* filename) = 0;


		virtual size_t LoadFont(const char* filename, int fileSize) = 0;
		virtual void DrawFont(int x, int y, int w, int h, size_t fontId, const char* text, const Color& color) = 0;
		virtual void DrawSprite(int x, int y, int w, int h, double angle, size_t fileId) = 0;
		virtual void DrawSprite(const RectI& src, const RectF& dst,
			double angle, const Flip& flip, const Color& color, size_t fileId) = 0;
		virtual void DrawSprite(const RectF& dst, const Color& color, size_t fileId) = 0;
		virtual void DrawSprite(const Color& color, size_t fileId) = 0;

		virtual void GetTextureSize(int* w, int* h) = 0;
		virtual void GetTextSize(const char* text, size_t fontId, int* w, int* h) = 0;

		virtual void Exit() = 0;
	};

}
