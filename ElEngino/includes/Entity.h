#pragma once


#include <string>
#include <vector>
#include <map>
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"

using namespace std;
//class Component;
namespace engino {
	class Entity final
	{
	public:
		Entity(const char* _name, float x, float y):name(_name), m_x(x),m_y(y)
		{

		};

		virtual void update(float dt) ;
		virtual void start();
		virtual void draw();
		virtual void Destroy();

		virtual const std::string getName() { return name; };
		virtual void setPos(float x, float y) { m_x = x; m_y = y; }
		virtual float GetX() { return m_x; }
		virtual float GetY() { return m_y; }
		virtual void SetX(float x) { m_x += x; }
		virtual void SetY(float y) { m_y += y; }
		void onCollision(Entity* other);

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
		const char* name;
		float m_x = 0;
		float m_y = 0;

	};


}