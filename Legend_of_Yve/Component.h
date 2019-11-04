#pragma once
#include "GameObject.h"

class GameLoop;
class RenderManager;

class Component
{
private:
	GameObject* _owner;
public:
	inline void SetGameObject(GameObject& t_gameObject) { _owner = &t_gameObject; };

	Component() { };
	virtual ~Component() { };
	virtual void Start() { };
	virtual void Update() { };
	virtual void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	virtual void DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager);
};

