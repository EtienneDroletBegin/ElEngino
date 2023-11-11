#pragma once
#include "SpriteRenderer.h"
#include "Engine.h"
#include <map>


namespace engino {

	struct Clip
	{
		int start = 0;
		int length = 0;
		float delay = 0;
		bool loop = true;
	};

	class Animation : public SpriteRenderer, public IUpdatable
	{
	public:
		Animation(Entity* parent) :SpriteRenderer(parent){}
		Animation() = default;
		~Animation() = default;
		virtual void Draw() override;
		void AddClip(const char* name, int start, int count, float delay);
		void Stop();
		void Update(float dt) override;
		void Play(const char* name, bool loop);
		void InitAnim(int _frameW, int _frameH);
		virtual void Destroy() override;


	protected:
		std::map<const char*, Clip> ClipMap;
		RectI currentFrame;
		Clip currentClip;

	private:
		int frameW = 18;
		int frameH = 18;
		float elapsed = 0;
		int FrameInt = 1;
	};

}