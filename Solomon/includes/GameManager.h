#pragma once
#include "Engine.h"
#include "IScenes.h"
#include "Spawner.h"


namespace engino {
	/// <summary>
	/// the container for the Spawner
	/// </summary>
	class GameManager: public Component
	{
	public:
		GameManager(Entity* parent) :Component(parent) {};
		~GameManager() {
			delete spawner;

		}
		/// <summary>
		/// returns the Spawner for use almost anywhere
		/// </summary>
		/// <returns>the spawner</returns>
		Spawner* spwnr() { return spawner; }

	private:
		Spawner* spawner = new Spawner();
	};

}