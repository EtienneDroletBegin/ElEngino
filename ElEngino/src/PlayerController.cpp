#include "PlayerController.h"
#include "Engine.h"

void engino::PlayerController::Update(float dt)
{
	if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::KEY_A)) {
		m_Entity->SetX(m_Entity->GetX() - 600 * dt);
	}
	if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::KEY_D)) {
		m_Entity->SetX(m_Entity->GetX() + 600 * dt);
	}
	if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::KEY_S)) {
		m_Entity->SetY(m_Entity->GetY() + 600 * dt);
	}
	if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::KEY_W)) {
		m_Entity->SetY(m_Entity->GetY() - 600 * dt);
	}

}
