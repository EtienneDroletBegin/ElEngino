#pragma once


#include <string>
#include <vector>
#include <map>
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"

using namespace std;
namespace engino {
	/// <summary>
	/// The possible direction flags for collisions
	/// </summary>
	enum class Directions
	{
		up = 1,
		down = 2,
		left = 4,
		right = 8
	};

	class Entity final
	{
	public:
		Entity(std::string _name, float x, float y):name(_name), m_x(x),m_y(y)
		{

		};

		/// <summary>
		/// called every frame
		/// </summary>
		/// <param name="dt">the time between each frame</param>
		virtual void update(float dt) ;
		virtual void start();
		virtual void draw();
		/// <summary>
		/// deletes the pointers to avoid memory leaks
		/// </summary>
		virtual void Destroy();

		/// <summary>
		/// returns the entity's name
		/// </summary>
		/// <returns>the entity' name</returns>
		virtual const std::string getName() { return name; };
		/// <summary>
		/// sets the entity's position
		/// </summary>
		/// <param name="x">the new X</param>
		/// <param name="y">the new Y</param>
		virtual void setPos(float x, float y) { m_x = x; m_y = y; }
		/// <summary>
		/// returns the X coordinate
		/// </summary>
		/// <returns>the X coordinate</returns>
		virtual float GetX() { return m_x; }
		/// <summary>
		/// returns the Y coordinate
		/// </summary>
		/// <returns>the Y coordinate</returns>
		virtual float GetY() { return m_y; }
		/// <summary>
		/// sets the X coordinate
		/// </summary>
		/// <param name="x">the new X coordinate</param>
		virtual void SetX(float x) { m_x = x; }
		/// <summary>
		/// sets the Y coordinate
		/// </summary>
		/// <param name="y">the new Y coordinate</param>
		virtual void SetY(float y) { m_y = y; }

		/// <summary>
		/// Adds a new Component to the entity
		/// </summary>
		/// <typeparam name="T">the Type of component to add</typeparam>
		/// <returns>the component for immediate init</returns>
		template <typename T> T* AddComponent() {
			T* cmp = new T(this);
			const type_info* type = &typeid(*cmp);
			IUpdatable* updatable = dynamic_cast<IUpdatable*>(cmp);
			if (updatable != nullptr) {
				m_updatable.push_back(updatable);
			}

			IDrawable* drawable = dynamic_cast<IDrawable*>(cmp);
			if (drawable != nullptr) {
				m_drawable.push_back(drawable);
			}
			m_Components[type] = cmp;
			cmp->Start();
			return cmp;
		}

		/// <summary>
		/// returns a given component
		/// </summary>
		/// <typeparam name="T">the component to get</typeparam>
		/// <returns>the component, nullptr if the entity doesnt have it</returns>
		template <typename T> T* GetComponent() {
			const std::type_info* typeInfo = &typeid(T);

			auto it = m_Components.find(typeInfo);
			if (it != m_Components.end()) {
				// Return the component pointer if found
				return dynamic_cast<T*>(it->second);
			}
			else {
				// Return nullptr if the component is not found
				return nullptr;
			}
		}


	private:
		
		vector<IUpdatable*> m_updatable;
		vector<IDrawable*> m_drawable;
		map<const type_info*, Component*> m_Components;
		std::string name;
		float m_x = 0;
		float m_y = 0;

	};


}