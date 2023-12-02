#include "Component.h"
#include "IUpdatable.h"
#include "Tilemap.h"
#include "Animation.h"
#include "GameManager.h"
#include "Subject.h"
#include "Atlas.h"
#include "BoxCollider.h"
#include "UI.h"

namespace engino {
	class PlayerController : public Component, public IUpdatable
	{
	public:
		PlayerController(Entity* parent) :Component(parent) {
			m_Entity->AddComponent<Animation>()->Init("assets/spriteSheet.png",1,1);
			m_Entity->GetComponent<Animation>()->InitAnim(14,14,3);
			m_Entity->GetComponent<Animation>()->AddClip("walk", 0, 4, 0.1f);
			m_Entity->GetComponent<Animation>()->AddClip("idle", 4, 1, 1);
			m_Entity->GetComponent<Animation>()->Play("idle", true);
			m_Entity->AddComponent<BoxCollider>()->Init(40, 40);
			m_tiles = Engine::Get()->wrld().GetEntity("map")->GetComponent<Tilemap>();
			m_animation = m_Entity->GetComponent<Animation>();
			OnTimeChange.AddListener(Engine::Get()->wrld().GetEntity("UI")->GetComponent<UI>());
			OnFireballChange.AddListener(Engine::Get()->wrld().GetEntity("UI2")->GetComponent<UI>());
			spwnr = Engine::Get()->wrld().GetEntity("spnwr")->GetComponent<GameManager>()->spwnr();
		};
		/// <summary>
		/// increments the player's fireballs
		/// </summary>
		void GainFireball();
		PlayerController() = default;
		~PlayerController() = default;
		virtual void Update(float dt) override;
		Subject<int> OnTimeChange;
		Subject<int> OnFireballChange;


	private:
		/// <summary>
		/// opens the door upon grabbing the key
		/// </summary>
		void UnlockDoor();
		/// <summary>
		/// throws a fireball
		/// </summary>
		void FireBall();
		void Jump(float dt);
		Tilemap* m_tiles;
		Animation* m_animation;
		Spawner* spwnr;

		float m_speed = 175;
		float jumpTime = 0;
		float fireballTime = 0;

		int Life = 15000;
		int fireballs = 0;

		bool canJump = true;
		bool canShoot = true;
		bool isJumping = false;

		bool crouch = false;

		bool canPlaceOrBreak = false;
		float placeBreakTime= 0;

		float lastX = 0;
		float lastY = 0;
		float velX = 0;
		float velY = 0;
	};

}

