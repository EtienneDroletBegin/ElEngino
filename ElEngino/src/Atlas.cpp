#include "Atlas.h"

void engino::Atlas::Draw()
{
	const float scale = 5;

	RectI dst = RectI();
	dst.x = m_Entity->GetX();
	dst.y = m_Entity->GetY();
	dst.w = currentFrame.w * scale;
	dst.h = currentFrame.h * scale;

	Engine::Get()->gfx().DrawSprite(currentFrame, dst, 0, Flip(), Color(255, 255, 255, 255), m_spriteID);
}

void engino::Atlas::Addframe(const char* name, int x, int y, int w, int h)
{
	RectI newRect{ x,y,w,h };
	Framesmap[name] = newRect;
}

void engino::Atlas::setFrame(const char* name)
{
	if (Framesmap.count(name) > 0)
	{
		currentFrame = Framesmap[name];
	}
}
