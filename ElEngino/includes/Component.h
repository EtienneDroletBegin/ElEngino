#pragma once

class Entity;

class Component
{
public:
	virtual ~Component() = default;
	Component();
	Component(Entity* parent);
	virtual void Start() {}
	virtual void Destroy() {}
protected:
	Entity* m_Entity = nullptr;
};


class IDrawable
{
public:
	virtual void Draw() = 0;
};


class IUpdatable {
public:
	virtual void Update() = 0;

};