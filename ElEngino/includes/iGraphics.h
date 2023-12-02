#pragma once

#include "Color.h"
#include <string>
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
		/// <summary>
		/// clears the render pipeline
		/// </summary>
		virtual void Clear() = 0;
		/// <summary>
		/// Render the stuff being drawn
		/// </summary>
		virtual void Present() = 0;
		/// <summary>
		/// Sets up what is needed for the graphics
		/// </summary>
		/// <param name="name">the name of the window</param>
		/// <param name="w">the width of the window</param>
		/// <param name="h">the width of the window</param>
		/// <returns></returns>
		virtual bool Initialize(std::string name, int w, int h)= 0;
		/// <summary>
		/// draws a line from point a to point b
		/// </summary>
		/// <param name="x1">point a x</param>
		/// <param name="y1"point b x></param>
		/// <param name="x2">point a y</param>
		/// <param name="y2">point b y</param>
		virtual void DrawRect(int x, int y, int w, int h) = 0;
		/// <summary>
		/// draws a rect
		/// </summary>
		/// <param name="x">the x</param>
		/// <param name="y">the y</param>
		/// <param name="w">the width</param>
		/// <param name="h"> the height</param>
		virtual void DrawRect(const RectI& rect, const Color& color) = 0;
		/// <summary>
		/// renders a rect
		/// </summary>
		/// <param name="rect">the rect to render</param>
		/// <param name="color">the color of the rect</param>
		virtual void FillRect(int x, int y, int w, int h) = 0;
		/// <summary>
		/// draws a filled rect
		/// </summary>
		/// <param name="x">the x</param>
		/// <param name="y">the y</param>
		/// <param name="w">the width</param>
		/// <param name="h">the height</param>
		virtual void FillRect(const RectI& rect, const Color& color) = 0;
		/// <summary>
		/// draws a filled rect
		/// </summary>
		/// <param name="rect">the rect to draw</param>
		/// <param name="color">the color of the rect</param>
		virtual void Drawline(int x1, int y1, int x2, int y2) = 0;
		/// <summary>
		/// creates a SDL_texture 
		/// </summary>
		/// <param name="filename">the path of the file to find</param>
		/// <returns>returns the texture's id</returns>
		virtual size_t LoadTexture(std::string filename) = 0;
		/// <summary>
		/// creates a SDL_Font
		/// </summary>
		/// <param name="filename">the path of the file to find</param>
		/// <param name="fileSize">the size</param>
		/// <returns></returns>
		virtual size_t LoadFont(std::string filename, int fileSize) = 0;
		/// <summary>
		/// draws a sprite
		/// </summary>
		/// <param name="x">the x</param>
		/// <param name="y">the y</param>
		/// <param name="w">the w</param>
		/// <param name="h">the h</param>
		/// <param name="angle">the angle of the sprite</param>
		/// <param name="fileId">the file's id (aquired through loadSprite)</param>
		virtual void DrawFont(float x, float y, int w, int h, size_t fontId, std::string text, const Color& color, int scale) = 0;
		/// <summary>
		/// draws a sprite
		/// </summary>
		/// <param name="src">the base image rect</param>
		/// <param name="dst">the destination to render</param>
		/// <param name="angle">the angle of the sprite</param>
		/// <param name="flip">is the sprite flipped</param>
		/// <param name="color">the color</param>
		/// <param name="fileId">the file's id (aquired through loadSprite)</param>
		virtual void DrawSprite(float x, float y, float w, float h, double angle, size_t fileId) = 0;
		virtual void DrawSprite(const RectI& src, const RectF& dst,
			double angle, const Flip& flip, const Color& color, size_t fileId) = 0;
		virtual void DrawSprite(const RectF& dst, const Color& color, size_t fileId) = 0;
		virtual void DrawSprite(const Color& color, size_t fileId) = 0;

		/// <summary>
		/// sets the correct metrics for the given image
		/// </summary>
		/// <param name="w">pointer to the width</param>
		/// <param name="h">pointer to the height</param>
		/// <param name="id">the texture's id in the hash</param>
		virtual void GetTextureSize(int* w, int* h, size_t id) = 0;
		/// <summary>
		/// sets the correct box size for the given text
		/// </summary>
		/// <param name="text">the text to write</param>
		/// <param name="fontId">the loaded font</param>
		/// <param name="w">the pointer to the width</param>
		/// <param name="h">the pointer to the height</param>
		virtual void GetTextSize(std::string text, size_t fontId, int* w, int* h) = 0;
		virtual void Exit() = 0;
	};

}
