#pragma once
#include "Engine.h"
#include "Colliders.h"

namespace engino {
	class BoxCollider : public Colliders
	{
	private:

	public:
		void Init(float _w, float _h) override;
		BoxCollider(Entity* parent):Colliders(parent){
			m_col = RectF();
			m_col.x = m_Entity->GetX();
			m_col.y = m_Entity->GetY();
		};
		BoxCollider() = default;
		virtual ~BoxCollider() = default;
		/// <summary>
		/// return the collider's width
		/// </summary>
		/// <returns>the collider's width</returns>
		virtual float getH() override { return m_col.h; };
		/// <summary>
		/// return the collider's height
		/// </summary>
		/// <returns>the collider's height</returns>
		virtual float getW() override { return m_col.w; };

		/// <summary>
		/// checks collisions between 2 box colliders
		/// </summary>
		/// <param name="cld">the parent entity</param>
		/// <param name="other">the other collider to check</param>
		/// <returns>wether the two colliders are colliding</returns>
		bool RectCollisions(Colliders* cld, Colliders* other);

		virtual void Update(float dt) override;

		RectF m_col;

	};
}