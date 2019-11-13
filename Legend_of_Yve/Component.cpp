#include "Component.h"
#include "GameLoop.h"
#include <iostream>

void Component::SetGameObject(GameObject* t_gameObject)
{
	_owner = t_gameObject;
}

bool Component::Active() const
{
	return _active;
}

void Component::SetActive(bool value)
{
	_active = value;
}

void Component::Register(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	t_gameLoop.Register(this);
}

void Component::DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	t_gameLoop.DeRegister(this);
}
