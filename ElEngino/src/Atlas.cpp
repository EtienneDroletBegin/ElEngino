#include "Atlas.h"

void engino::Atlas::Draw()
{
	const int scale = 5;

	RectF dst = RectF();
	dst.x = m_Entity->GetX();
	dst.y = m_Entity->GetY();
	dst.w = static_cast<float>(currentFrame.w * scale);
	dst.h = static_cast<float>(currentFrame.h * scale);

	Engine::Get()->gfx().DrawSprite(currentFrame, dst, 0, Flip(), Color(255, 255, 255, 255), m_spriteID);
}

void engino::Atlas::Addframe(std::string name, int x, int y, int w, int h)
{
	RectI newRect{ x,y,w,h };
	Framesmap[name] = newRect;
}

void engino::Atlas::setFrame(std::string name)
{
	if (Framesmap.count(name) > 0)
	{
		currentFrame = Framesmap[name];
	}
}
