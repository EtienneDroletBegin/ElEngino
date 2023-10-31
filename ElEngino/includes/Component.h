#pragma once
#include "Entity.h"
namespace engino {
	class Component
	{
	public:
		virtual ~Component() = default;
		Component(Entity* parent) :m_Entity(parent){};
		Component() = default;
		virtual void Start() {}
		virtual void Destroy() {}
	protected:
		Entity* m_Entity = nullptr;
	};

}