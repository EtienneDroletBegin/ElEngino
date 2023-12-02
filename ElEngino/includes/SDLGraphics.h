#pragma once
#include "iGraphics.h"
#include "map"

struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
typedef struct SDL_Renderer SDL_Renderer;
typedef struct SDL_Window SDL_Window;

namespace engino {

	class SDLGraphics final : public IGraphics

	{
	public:
		SDLGraphics() = default;
		~SDLGraphics() = default;
		/// <summary>
		/// sets the render color
		/// </summary>
		/// <param name="color">the color to set to</param>
		virtual void SetColor(const Color& color) override;
		/// <summary>
		/// clears the render in preparation for the next one
		/// </summary>
		virtual void Clear() override;
		/// <summary>
		/// renders the new frame on screen
		/// </summary>
		virtual void Present() override;
		/// <summary>
		/// initializes the window
		/// </summary>
		/// <param name="name">the window's name</param>
		/// <param name="w">the width of the window</param>
		/// <param name="h">the height of the window</param>
		/// <returns>whether the initialization is done</returns>
		virtual bool Initialize(std::string name, int w, int h) override;

		/// <summary>
		/// draws a line between two points
		/// </summary>
		/// <param name="x1">point one X</param>
		/// <param name="y1">point one Y</param>
		/// <param name="x2">point two X</param>
		/// <param name="y2">point two Y</param>
		virtual void Drawline(int x1, int y1, int x2, int y2) override;
		/// <summary>
		/// draws an empty rectangle
		/// </summary>
		/// <param name="x">the X</param>
		/// <param name="y">the Y</param>
		/// <param name="w">the width</param>
		/// <param name="h">the height</param>
		virtual void DrawRect(int x, int y, int w, int h) override;
		virtual void DrawRect(const RectI& rect, const Color& color) override;
		/// <summary>
		/// draws a full rectangle
		/// </summary>
		/// <param name="x">the X</param>
		/// <param name="y">the Y</param>
		/// <param name="w">the width</param>
		/// <param name="h">the height</param>
		virtual void FillRect(int x, int y, int w, int h) override;
		virtual void FillRect(const RectI& rect, const Color& color) override;

		/// <summary>
		/// reads an image file and creates an SDL_Texture
		/// </summary>
		/// <param name="filename">the file name in the game files</param>
		/// <returns></returns>
		virtual size_t LoadTexture(std::string filename) override;

		/// <summary>
		/// reads a ttf file and creates a TTF_Font
		/// </summary>
		/// <param name="filename">the file name in the GameFiles</param>
		/// <param name="fileSize"></param>
		/// <returns></returns>
		virtual size_t LoadFont(std::string filename, int fileSize) override;

		virtual void DrawSprite(float x, float y, float w, float h, double angle, size_t fileId) override;
		virtual void DrawSprite(const RectI& src, const RectF& dst,
			double angle, const Flip& flip, const Color& color, size_t fileId) override;
		virtual void DrawSprite(const RectF& dst, const Color& color, size_t fileId) override;
		virtual void DrawSprite(const Color& color, size_t fileId) override;

		virtual void GetTextureSize(int* w, int* h, size_t id) override;
		virtual void GetTextSize(std::string text, size_t fontId, int* w, int* h);

		virtual void DrawFont(float x, float y, int w, int h, size_t fontId, std::string text, const Color& color, int scale) override;
		virtual void Exit() override;


	private:
		SDL_Renderer* renderer;
		SDL_Window* Window;
		std::map<size_t, SDL_Texture*> *hashMap = new std::map<size_t, SDL_Texture*>();
		std::map<size_t, TTF_Font*> *FontHash = new std::map<size_t, TTF_Font*>();
	};

}

