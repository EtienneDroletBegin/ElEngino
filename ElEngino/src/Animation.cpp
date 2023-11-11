#include "Animation.h"
#include "SpriteRenderer.h"



void engino::Animation::Draw()
{
	currentFrame = RectI{ FrameInt*18,0,18,18 };

	const float scale = 5;

	RectI dst = RectI();
	dst.x = m_Entity->GetX();
	dst.y = m_Entity->GetY();
	dst.w = currentFrame.w * scale;
	dst.h = currentFrame.h * scale;
	Engine::Get()->gfx().DrawSprite(currentFrame, dst, 0, Flip(), Color(255, 255, 255, 255), m_spriteID);
}


/// <summary>
/// Adds a Clip() to the Clip Map with a name
/// </summary>
/// <param name="name">The name of the clip</param>
/// <param name="_start">the frame count of the start of the animation</param>
/// <param name="_count">the length of the animation</param>
/// <param name="_delay">the time between each frame</param>
void engino::Animation::AddClip(const char* name, int _start, int _count, float _delay)
{
	Clip newClip{ _start, _count, _delay };
	ClipMap[name] = newClip;
}

void engino::Animation::Stop()
{
}

void engino::Animation::Update(float dt)
{
	elapsed += dt;
	if (elapsed >= currentClip.delay) {
		FrameInt++;
		elapsed = 0;
		currentFrame.x = frameW * FrameInt;
		if (FrameInt >= currentClip.start + currentClip.length) {
			FrameInt = currentClip.start;
		}
	}
}

/// <summary>
/// plays the given animation by name
/// </summary>
/// <param name="name">name of the animation to play</param>
/// <param name="loop">bool if the animation loops</param>
void engino::Animation::Play(const char* name, bool loop)
{
	if (ClipMap.count(name) > 0)
	{
		currentClip = ClipMap[name];
		FrameInt = currentClip.start;
	}
}

/// <summary>
/// sets the width and height of the Rect (not used currently)
/// </summary>
/// <param name="_frameW">the width</param>
/// <param name="_frameH">the height</param>
void engino::Animation::InitAnim(int _frameW, int _frameH)
{
	frameH = _frameH;
	frameW = _frameW;
}

void engino::Animation::Destroy()
{
	delete m_Entity;
}
