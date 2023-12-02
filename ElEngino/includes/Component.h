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
		/// <summary>
		/// when the component is initialized
		/// </summary>
		virtual void Start() {}
		/// <summary>
		/// destroys every pointers to avoid memory leaks
		/// </summary>
		virtual void Destroy() {}
		Entity* m_Entity = nullptr;
	protected:
	};

}