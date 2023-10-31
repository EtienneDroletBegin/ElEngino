#pragma once
#include <string>
#include <vector>
#include <map>
#include "IUpdatable.h"
#include "IDrawable.h"

class Component;
namespace engino {
	class Entity final
	{
	public:
		Entity(const char* _name):name(_name), m_x(0),m_y(0),m_spriteID(0)
		{
		};

		virtual void update(float dt) ;
		virtual void start();
		virtual void draw();
		virtual void Destroy();

		virtual const std::string getName() { return name; };
		virtual void setPos(int x, int y) { m_x = x; m_y = y; }
		virtual float GetX() { return m_x; }
		virtual float GetY() { return m_y; }
		virtual void SetX(int x) { m_x = x; }
		virtual void SetY(int y) { m_y = y; }

		template <typename T>
		void AddComponent() {
			T cmp = new T(this);
			const type_info* type = &typeid(*cmp);

			IUpdatable* updatable = dynamic_cast<IUpdatable*>(cmp);
			if (updatable != nullptr) {
				m_updatable.emplace(type, updatable)
			}

			IDrawable* drawable = dynamic_cast<IDrawable*>(cmp);
			if (drawable != nullptr) {
				m_drawable.emplace(type, updatable)
			}

			m_components.push_back(cmp);
		}

	private:
		size_t m_spriteID;
		std::vector<Component*> m_components;
		std::map<const type_info*, IUpdatable*> m_updatable;
		std::map<const type_info*, IDrawable*> m_drawable;
		const char* name;
		float m_x;
		float m_y;

	};


}