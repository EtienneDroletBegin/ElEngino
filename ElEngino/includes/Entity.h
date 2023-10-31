#pragma once
#include <string>
#include <vector>
#include <map>
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"

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

		template <typename T>
		void AddComponent(T cmp);

	private:
		size_t m_spriteID;
		std::vector<Component*> m_components;
		std::map<const type_info*, IUpdatable*> m_updatable;
		std::map<const type_info*, IDrawable*> m_drawable;

	protected:
		const char* name;
		float m_x;
		float m_y;

	};


}