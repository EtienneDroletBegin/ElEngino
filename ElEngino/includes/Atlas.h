#pragma once
#include "SpriteRenderer.h"
#include "Engine.h"
#include <map>

namespace engino {
	class Atlas : public SpriteRenderer
	{
	public:
		Atlas(Entity* parent) :SpriteRenderer(parent) {
			currentFrame = RectI();
		}
		Atlas() = default;
		~Atlas() = default;
		virtual void Draw() override;
		/// <summary>
		/// Adds a frame to the atlas
		/// </summary>
		/// <param name="name">the frame's name</param>
		/// <param name="x">the x position on the spritesheet</param>
		/// <param name="y">the y position on the spritesheet</param>
		/// <param name="w">the width on the spritesheet</param>
		/// <param name="h">the height on the spritesheet</param>
		void Addframe(std::string name, int x, int y, int w, int h);
		/// <summary>
		/// changes the active frame
		/// </summary>
		/// <param name="name">the frame's name</param>
		void setFrame(std::string name);


	protected:
		std::map<std::string, RectI> Framesmap;
		RectI currentFrame;
	};

}