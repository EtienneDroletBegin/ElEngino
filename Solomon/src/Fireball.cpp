#include "Fireball.h"
#include "Monster.h"
#include "Runner.h"

using namespace engino;

void engino::Fireball::Init(int _dir)
{
	m_dir = _dir;
	if (m_dir == 0) {
		m_speed *= -1;
	}

	m_Entity->GetComponent<Animation>()->SetCol(m_dir);
}

void engino::Fireball::Update(float dt)
{
	m_Entity->SetX(m_Entity->GetX() + m_speed * dt);

	int dir = 0;
	for (int i = 0; i < m_map->GetLayer("map").size(); i++) {
		if (m_map->IsColliding("map", m_Entity, &i, &dir) || m_map->IsColliding("breakables", m_Entity, &i, &dir))
		{
			m_Entity->setPos(-100, -100);
			m_Entity->GetComponent<BoxCollider>()->m_col.x = -100;
			Engine::Get()->wrld().Remove(m_Entity);
		}
	}

}

IClonable* engino::Fireball::Clone(float x, float y, int index)
{
	Entity* proto = Engine::Get()->wrld().Create("fireball" + index, x, y);
	Fireball* fireball = proto->AddComponent<Fireball>();
	fireball->Init(Engine::Get()->wrld().GetEntity("player")->GetComponent<Animation>()->GetCol());
	return fireball;
}
