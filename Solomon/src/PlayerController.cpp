#include "PlayerController.h"
#include "Action.h"
#include "Engine.h"

using namespace engino;


void PlayerController::Update(float dt)
{
	m_Entity->SetY(m_Entity->GetY() + 250 * dt);

	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_W)) {
		if (canJump)
		{
			isJumping = true;
			canJump = false;
		}
	}
	if (isJumping)
	{
		Jump(dt);
	}

	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_S)) {
		crouch = true;
	}
	else {
		crouch = false;
	}

	if (Engine::Get()->input().IsKeyDown(EKeycodes::Key_Space)) {
		if (canPlaceOrBreak)
		{
			canPlaceOrBreak = false;
			m_tiles->NextTile(m_Entity, m_animation->GetCol(), crouch);

		}
	}

	velY = m_Entity->GetY() - lastY;

	int dir = 0;
	for (int i = 0; i < m_tiles->GetLayer("map").size(); i++) {
		if (m_tiles->IsColliding("map", m_Entity, &i, &dir) || m_tiles->IsColliding("breakables", m_Entity, &i, &dir))
		{
			if (dir & (int)Directions::down)
			{
				m_Entity->SetY(m_Entity->GetY() - velY);
				if (!isJumping)
				{
					canJump = true;
				}

			}
			if (dir & (int)Directions::up)
			{
				isJumping = false;
			}
		}
	}

	if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_A)) {
		m_Entity->SetX(m_Entity->GetX()+ m_speed * -1 * dt);
		m_animation->SetCol(0);
		m_animation->Play("walk", true);
	}
	else if (Engine::Get()->input().IsKeyDown(EKeycodes::KEY_D)) {
		m_Entity->SetX(m_Entity->GetX() + m_speed * dt);
		m_animation->SetCol(1);
		m_animation->Play("walk", true);
	}
	else {
		m_animation->Play("idle", true);
	}

	velX = m_Entity->GetX() - lastX;
	dir = 0;
	for (int i = 0; i < m_tiles->GetLayer("map").size(); i++) {
		if (m_tiles->IsColliding("map", m_Entity, &i, &dir) || m_tiles->IsColliding("breakables", m_Entity, &i, &dir))
		{
			if (dir & (int)Directions::left || dir & (int)Directions::right)
			{
				m_Entity->SetX(m_Entity->GetX() - velX);
			}
		}
	}
	if (Engine::Get()->input().IsKeyDown(EKeycodes::Key_R)) {
		if (canShoot && fireballs > 0)
		{
			canShoot = false;
			FireBall();
		}
	}

	BoxCollider* collider = m_Entity->GetComponent<BoxCollider>();
	BoxCollider* key = Engine::Get()->wrld().GetEntity("key")->GetComponent<BoxCollider>();
	if (collider->RectCollisions(collider, key)) {
		Engine::Get()->Aduio()->PlaySFX(Engine::Get()->Aduio()->LoadSound("assets/powerup.wav"), false);
		key->m_Entity->SetX(-100);
		key->m_col.x = -100;
		UnlockDoor();
	}

	for (int i = 0; i < m_tiles->GetLayer("map").size(); i++) {
		if (m_tiles->IsColliding("Door", m_Entity, &i, &dir) || m_tiles->IsColliding("breakables", m_Entity, &i, &dir))
		{
			if (i == 19) {
				engino::Engine::Get()->wrld().Load("Win");
				return;
			}
		}
	}


	lastX = m_Entity->GetX();
	lastY = m_Entity->GetY();
	if (!canPlaceOrBreak)
	{
		placeBreakTime += dt;
		if (placeBreakTime > 0.5)
		{
			placeBreakTime = 0;
			canPlaceOrBreak = true;
		}
	}
	Life -= 1;
	PlayerStats stats = {0};
	stats._time = Life;
	stats._fireballs = fireballs;
	OnTimeChange.Invoke(stats._time);

	if (!canShoot)
	{
		fireballTime += dt;
		if (fireballTime >= 2) {
			canShoot = true;
			fireballTime = 0;
		}
	}
}

void engino::PlayerController::Jump(float dt) {
	m_Entity->SetY(m_Entity->GetY()  -550 * dt);
	jumpTime += dt;
	if (jumpTime >= 0.23f)
	{
		jumpTime = 0;
		isJumping = false;
		m_Entity->SetY(m_Entity->GetY() + 10);
	}
}

void engino::PlayerController::UnlockDoor()
{
	Entity* map = Engine::Get()->wrld().GetEntity("map");
	map->GetComponent<Tilemap>()->switchTile("Door", 13, 19);

	Engine::Get()->wrld().Remove(Engine::Get()->wrld().GetEntity("key"));
}

void engino::PlayerController::FireBall()
{
	std::cout << "shoot";
	spwnr->Spawn("fireballPrototype", m_Entity->GetX(), m_Entity->GetY());
	fireballs--;
	Engine::Get()->Aduio()->PlaySFX(Engine::Get()->Aduio()->LoadSound("assets/shoot.wav"), false);
	OnFireballChange.Invoke(fireballs);
}

void engino::PlayerController::GainFireball()
{
	Engine::Get()->Aduio()->PlaySFX(Engine::Get()->Aduio()->LoadSound("assets/powerup.wav"), false);
	fireballs++;
	OnFireballChange.Invoke(fireballs);
}
