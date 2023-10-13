#pragma once
#include <string>

struct SDL_Texture;

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

		virtual const std::string getName() { return name; };
		virtual void setPos(int x, int y) { m_x = x; m_y = y; }
		virtual float GetX() { return m_x; }
		virtual float GetY() { return m_y; }
		//void AddComponent(Component* comp);

	private:
		size_t m_spriteID;

	protected:
		const char* name;
		float m_x;
		float m_y;

	};


}