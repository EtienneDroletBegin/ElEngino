#include "PlayerController.h"
#include "Engine.h"

using namespace engino;


void PlayerController::Update(float dt)
{
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_A)) {
		m_Entity->SetX(-800 * dt );
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_D)) {
		m_Entity->SetX(800 * dt);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_S)) {
		m_Entity->SetY(800 * dt);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_W)) {
		m_Entity->SetY(-800 * dt);
	}

}
