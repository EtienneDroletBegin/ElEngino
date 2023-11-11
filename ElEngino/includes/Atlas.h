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

		void Addframe(const char* name, int x, int y, int w, int h);
		void setFrame(const char* name);


	protected:
		std::map<const char*, RectI> Framesmap;
		RectI currentFrame;
	};

}