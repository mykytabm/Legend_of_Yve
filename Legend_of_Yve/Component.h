#pragma once
#include "GameObject.h"

class GameLoop;
class RenderManager;

class Component
{
private:
	GameObject* m_owner;
public:
	inline void SetGameObject(GameObject& t_gameObject) { m_owner = &t_gameObject; };

	Component() {};
	virtual ~Component() {};
	virtual void Start() {};
	virtual void update() {};
	virtual void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager);
};

