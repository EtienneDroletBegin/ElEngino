#pragma once
#include <string>
//#include "Entity.h"
namespace engino {
	class Entity;
	class Component
	{
	public:
		virtual ~Component() = default;
		Component(Entity* parent) :m_Entity(parent){};
		Component() = default;
		virtual void Start() {}
		virtual void Destroy() {}
		Entity* m_Entity = nullptr;
	protected:
	};

}