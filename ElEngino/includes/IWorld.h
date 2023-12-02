#pragma once
#include <vector>
#include <string>
namespace engino {
	class Entity;
	class Colliders;
	class Spawner;
	class IScenes;
	class IWorld
	{
	private:

	public:

		/// <summary>
		/// Creates a new entity and calls the add function
		/// </summary>
		/// <param name="name">the entity's name</param>
		/// <param name="x">the X coordinate to spawn itr at</param>
		/// <param name="y">the Y coordinate to spawn itr at</param>
		/// <returns>the created entity</returns>
		virtual Entity* Create(std::string name, float x, float y) = 0;
		/// <summary>
		/// adds the entity to the entity map in the world
		/// </summary>
		/// <param name="added">the new entity</param>
		void virtual Add(Entity* added) = 0;
		/// <summary>
		/// removes an entity from the map and prepares it to be destroyed
		/// </summary>
		/// <param name="entity">the entity to destroy</param>
		virtual void Remove(Entity* entity) = 0;
		void virtual Start() = 0;
		void virtual Update(float dt) = 0;
		void virtual Draw() = 0;
		/// <summary>
		/// unloads the previous scene and loads a given scene
		/// </summary>
		/// <param name="scene">the given scene</param>
		void virtual Load(std::string scene) = 0;
		/// <summary>
		/// adds a new scene to the scene map
		/// </summary>
		/// <param name="name">the scene's name</param>
		/// <param name="scene">the new scene</param>
		virtual void Register(std::string name, IScenes* scene) = 0;
		virtual void Exit() = 0;
		/// <summary>
		/// adds a collider to the collider vector for easy access for collision check
		/// </summary>
		/// <param name="col">the collider</param>
		virtual void AddCollider(Colliders* col)=0;
		/// <summary>
		/// returns all existing colliders
		/// </summary>
		/// <returns>the vector of all colliders</returns>
		virtual std::vector<Colliders*> GetColliders() = 0;
		/// <summary>
		/// returns an entity with a given name
		/// </summary>
		/// <param name="name">the given name</param>
		/// <returns>the entity / nullptr if not found</returns>
		virtual Entity* GetEntity(std::string name) = 0;

	};

}