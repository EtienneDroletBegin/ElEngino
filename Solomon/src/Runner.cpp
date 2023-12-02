#include "Runner.h"

using namespace engino;

void engino::Runner::Init(float speed)
{
	m_Speed = speed;
}

Runner* engino::Runner::Clone(float x, float y, int index)
{
	Entity* proto = Engine::Get()->wrld().Create("monster" + index, x, y);
	proto->AddComponent<Runner>()->Init(70);
	return proto->GetComponent<Runner>();
}


void engino::Runner::Update(float dt)
{
	Monster::Update(dt);
	m_Entity->SetY(m_Entity->GetY() + 100 * dt);


	float velY = m_Entity->GetY() - lastY;
	int dir = 0;
	for (int i = 0; i < m_tiles->GetLayer("map").size(); i++) {
		if (m_tiles->IsColliding("map", m_Entity, &i, &dir) || m_tiles->IsColliding("breakables", m_Entity, &i, &dir))
		{
			if (dir & (int)Directions::down)
			{
				m_Entity->SetY(m_Entity->GetY() - velY);
			}
		}
	}

	m_Entity->SetX(m_Entity->GetX() + m_Speed*dt);

	float velX = m_Entity->GetX() - lastX;
	dir = 0;
	for (int i = 0; i < m_tiles->GetLayer("map").size(); i++) {
		if (m_tiles->IsColliding("map", m_Entity, &i, &dir) || m_tiles->IsColliding("breakables", m_Entity, &i, &dir))
		{
			if (dir & (int)Directions::left || dir & (int)Directions::right)
			{
				m_Speed *= -1;
				m_Entity->SetX(m_Entity->GetX() - velX);
				if (m_Entity->GetComponent<Animation>()->GetCol() == 0) {
					m_Entity->GetComponent<Animation>()->SetCol(1);
				}
				else {
					m_Entity->GetComponent<Animation>()->SetCol(0);
				}
			}
		}
	}

	lastY = m_Entity->GetY();
	lastX = m_Entity->GetX();


	BoxCollider* collider = m_Entity->GetComponent<BoxCollider>();
	BoxCollider* plyr = Engine::Get()->wrld().GetEntity("player")->GetComponent<BoxCollider>();

	if (collider->RectCollisions(collider, plyr)) {
		Engine::Get()->wrld().Load("Lose");
	}
}
