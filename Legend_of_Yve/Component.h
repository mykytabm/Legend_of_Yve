#pragma once
#include "GameObject.h"
class GameLoop;
class RenderManager;
class Component
{
private:
	GameObject* m_owner;

public:
	void SetGameObject(GameObject* t_gameObject)
	{
		if (t_gameObject != nullptr) m_owner = t_gameObject;
	};

	virtual ~Component() { };
	virtual void update() {};
	virtual void Register(GameLoop* t_gameLoop, RenderManager* t_renderManager);
};

