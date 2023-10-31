#include "Entity.h"
#include "Engine.h"
#include <iostream>

using namespace engino;


void engino::Entity::update(float dt)
{


	for (auto c : m_components) {

	}
}

void engino::Entity::start()
{
	m_spriteID = Engine::Get()->gfx().LoadTexture("assets/Gorgo.png");
}

void engino::Entity::draw()
{
	for (auto c : m_components) {

	}

	Engine::Get()->gfx().DrawSprite(m_x, m_y, 696, 564, 0, m_spriteID);

}

void engino::Entity::Destroy()
{
	delete name;
}
