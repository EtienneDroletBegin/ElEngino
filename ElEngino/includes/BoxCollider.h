#pragma once
#include "Engine.h"
#include "Colliders.h"

namespace engino {
	class BoxColliders : public Colliders
	{
	private:

	public:
		void Start() override;
		BoxColliders(Entity* parent):Colliders(parent){
			m_col = RectF();
			m_col.h = 60.0f;
			m_col.w = 60.0f;
			m_col.x = m_Entity->GetX();
			m_col.y = m_Entity->GetY();
		};
		BoxColliders() = default;
		~BoxColliders() = default;
		virtual float getH() override { return m_col.h; };
		virtual float getW() override { return m_col.w; };

		void RectCollisions(Colliders* cld);

		virtual void Update(float dt) override;

		RectF m_col;

	};
}