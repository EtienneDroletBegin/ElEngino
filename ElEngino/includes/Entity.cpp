#include "Entity.h"
#include "Engine.h"
#include "Component.h"
#include <iostream>

using namespace engino;



void engino::Entity::update(float dt)
{
	for (auto c : m_updatable) {
		c->Update(dt);
	}
}

void engino::Entity::start()
{
	
}

void engino::Entity::draw()
{
	for (auto c : m_drawable) {
		c->Draw();
	}

}

void engino::Entity::Destroy()
{
    for (auto it : m_Components)
    {
		delete it.second;
    }

    m_Components.clear();
    m_updatable.clear();
    m_drawable.clear();
}
