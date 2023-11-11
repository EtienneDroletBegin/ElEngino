#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"

namespace engino {
	class SpriteRenderer : public Component, public IDrawable
	{
	public:
		void Init(const char* filename);
		SpriteRenderer(Entity* parent):Component(parent) {
			m_spriteID = 0;
		}
		SpriteRenderer() = default;
		~SpriteRenderer()= default;
		virtual void Draw() override;

	protected:
		size_t m_spriteID;
	};
}