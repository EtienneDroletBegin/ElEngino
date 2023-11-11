#include "PlayerController.h"
#include "Atlas.h"
#include "Animation.h"
#include "Engine.h"

using namespace engino;


void PlayerController::Update(float dt)
{
	//m_Entity->GetComponent<Animation>()->Play("idle", true);
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_A)) {
		m_Entity->SetX(-200 * dt );
		//m_Entity->GetComponent<Animation>()->Play("walk", true);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_D)) {
		//m_Entity->GetComponent<Animation>()->Play("walk", true);
		m_Entity->SetX(200 * dt);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_S)) {
		//m_Entity->GetComponent<Animation>()->Play("walk", true);
		m_Entity->SetY(200 * dt);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_W)) {
		//m_Entity->GetComponent<Animation>()->Play("walk", true);
		m_Entity->SetY(-200 * dt);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::Key_T)) {
		m_Entity->GetComponent<Animation>()->Play("walk", true);
		//m_Entity->SetY(-200 * dt);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::Key_Y)) {
		m_Entity->GetComponent<Animation>()->Play("idle", true);
		//m_Entity->SetY(-200 * dt);
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::Key_R)) {
		//FireBall();
	}

}

void engino::PlayerController::FireBall()
{
	Entity* added = Engine::Get()->wrld().Create("fireball", m_Entity->GetX(), m_Entity->GetY());
	added->AddComponent<SpriteRenderer>()->Init("assets/fireball.png");
}
