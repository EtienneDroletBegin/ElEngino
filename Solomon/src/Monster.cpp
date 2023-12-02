#include "Engine.h"
#include "Monster.h"
#include "Fireball.h"

using namespace engino;

void engino::Monster::Update(float dt)
{
	for each (Colliders * col in Engine::Get()->wrld().GetColliders())
	{
		if (col->m_Entity->GetComponent<Fireball>()) {
			BoxCollider* my_col = m_Entity->GetComponent<BoxCollider>();
			if (my_col->RectCollisions(my_col, col)) {
				col->m_Entity->setPos(-100, -100);
				col->m_Entity->GetComponent<BoxCollider>()->m_col.x = -100;
				my_col->m_Entity->SetX(-100);
				my_col->m_col.x = -100;
				Engine::Get()->wrld().Remove(col->m_Entity);
				Engine::Get()->wrld().Remove(m_Entity);
			}
		}
	}
}
