#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"

namespace engino {
	class SpriteRenderer : public Component, public IDrawable
	{
	public:
		/// <summary>
		/// initiates the necessary components
		/// </summary>
		/// <param name="filename">the file with the sprite</param>
		void Init(std::string filename, float _w, float _h);
		SpriteRenderer(Entity* parent):Component(parent) {
			m_spriteID = 0;
		}
		SpriteRenderer() = default;
		~SpriteRenderer()= default;
		virtual void Draw() override;

	protected:
		size_t m_spriteID;
		float m_w;
		float m_h;
	};
}