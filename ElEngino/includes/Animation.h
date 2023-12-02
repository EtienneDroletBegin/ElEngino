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
		int id;
	};

	class Animation : public SpriteRenderer, public IUpdatable
	{
	public:
		Animation(Entity* parent) :SpriteRenderer(parent){
			
		}
		Animation() = default;
		~Animation() = default;
		virtual void Draw() override;
		/// <summary>
		/// Adds an animation clip to the map
		/// </summary>
		/// <param name="name">name of the clip</param>
		/// <param name="start">the start frame of the clip</param>
		/// <param name="count">the length in frames of the clip</param>
		/// <param name="delay">how long to wait between frames</param>
		void AddClip(std::string name, int start, int count, float delay);
		/// <summary>
		/// Returns the currently playing clip
		/// </summary>
		/// <returns>the currently playing clip</returns>
		Clip* GetCurrentClip() { return &currentClip; };
		/// <summary>
		/// returns a clip in the map
		/// </summary>
		/// <param name="clipName">the name of the clip</param>
		/// <returns>the clip with the received name</returns>
		Clip* GetClip(std::string clipName) { return &ClipMap[clipName]; };
		
		void Stop();
		/// <summary>
		/// executed every frame
		/// </summary>
		/// <param name="dt">time between last frame and current</param>
		void Update(float dt) override;
		/// <summary>
		/// changes the currentClip to a new one to play it
		/// </summary>
		/// <param name="name">the name of the clip</param>
		/// <param name="loop">should it loop</param>
		void Play(std::string name, bool loop);
		/// <summary>
		/// initiates the necessary variables
		/// </summary>
		/// <param name="_frameW">the frame Rect's width</param>
		/// <param name="_frameH">the frame Rect's height</param>
		void InitAnim(int _frameW, int _frameH, float scale);
		/// <summary>
		/// destroys the pointers to avoid memory leak
		/// </summary>
		virtual void Destroy() override;
		/// <summary>
		/// Sets the row for the animation to play (serves for character orientation)
		/// </summary>
		/// <param name="col">the col</param>
		void SetCol(int col) { m_col = col; }
		/// <summary>
		/// returns the current animation row (serves to detect character orientation)
		/// </summary>
		/// <returns>returns the row</returns>
		int GetCol() { return m_col; }


	protected:
		std::map<std::string, Clip> ClipMap;
		RectI currentFrame;
		Clip currentClip;

	private:
		float m_scale;
		int m_col=0;
		int frameW = 14;
		int frameH = 14;
		float elapsed = 0;
		int FrameInt = 1;
	};

}