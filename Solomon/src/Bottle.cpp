#include "Bottle.h"
#include "PlayerController.h"

using namespace engino;

void engino::Bottle::Update(float dt)
{
	BoxCollider* collider = m_Entity->GetComponent<BoxCollider>();
	BoxCollider* plyr = Engine::Get()->wrld().GetEntity("player")->GetComponent<BoxCollider>();
	if (collider->RectCollisions(collider, plyr)) {
		plyr->m_Entity->GetComponent<PlayerController>()->GainFireball();
		Engine::Get()->wrld().Remove(m_Entity);
	}
}

IClonable* engino::Bottle::Clone(float x, float y, int index)
{
	Entity* proto = Engine::Get()->wrld().Create("bottle" + index, x, y);
	Bottle* bottle = proto->AddComponent<Bottle>();
	return bottle;
}
