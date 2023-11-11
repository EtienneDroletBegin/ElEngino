#include "BoxCollider.h"
#include <vector>
#include <iostream>
#include "Text.h"
#include "Engine.h"



void engino::BoxColliders::Update(float dt)
{
	m_col.x = m_Entity->GetX();
	m_col.y = m_Entity->GetY();
	for each (Colliders* cld in Engine::Get()->wrld().GetColliders())
	{
        if (cld == nullptr)
        {
            break;
        }
        if (cld != this) {
            RectCollisions(cld);
		}
        //else if(ntt->GetComponent<SphereCollider>() != nullptr && ntt != this->m_Entity)
	}
}

void engino::BoxColliders::Start()
{
    Engine::Get()->wrld().AddCollider(this);
}

/// <summary>
/// Checks the collision between two box colliders
/// </summary>
/// <param name="cld">the other collider</param>
void engino::BoxColliders::RectCollisions(Colliders* cld)
{
    RectF r1 = m_col;
    RectF r2 = dynamic_cast<BoxColliders*>(cld)->m_col;

    // Check for horizontal overlap
    bool xOverlap = r1.x + r1.w >= r2.x && r2.x + r2.w >= r1.x;
    // Check for vertical overlap
    bool yOverlap = r1.y + r1.h >= r2.y && r2.y + r2.h >= r1.y;

    if (xOverlap && yOverlap) {
       Engine::Get()->wrld().GetEntity("Col")->GetComponent<Text>()->SetText("collision detected");
       //Engine::Get()->wrld().GetEntity("Col")->GetComponent<Text>()->SetText("collision detected");
     
    }
    else {
        Engine::Get()->wrld().GetEntity("Col")->GetComponent<Text>()->SetText("no collision detected");

    }
}