#include "BoxCollider.h"
#include <vector>
#include <iostream>
#include "Text.h"
#include "Engine.h"



void engino::BoxCollider::Update(float dt)
{
	m_col.x = m_Entity->GetX();
	m_col.y = m_Entity->GetY();
}

void engino::BoxCollider::Init(float _w, float _h)
{
    m_col.h = _h;
    m_col.w = _w;
    Engine::Get()->wrld().AddCollider(this);
}

/// <summary>
/// Checks the collision between two box colliders
/// </summary>
/// <param name="cld">the other collider</param>
bool engino::BoxCollider::RectCollisions(Colliders* cld, Colliders* other)
{
    RectF r1 = dynamic_cast<BoxCollider*>(other)->m_col;
    RectF r2 = dynamic_cast<BoxCollider*>(cld)->m_col;

    // Check for horizontal overlap
    bool xOverlap = r1.x + r1.w >= r2.x && r2.x + r2.w >= r1.x;
    // Check for vertical overlap
    bool yOverlap = r1.y + r1.h >= r2.y && r2.y + r2.h >= r1.y;

    return xOverlap && yOverlap;
}