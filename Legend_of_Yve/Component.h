#pragma once
#include "GameObject.h"

class GameLoop;
class RenderManager;

class Component
{
private:
	GameObject* _owner;
	bool _active = true;
public:
	inline void SetGameObject(GameObject& t_gameObject) { _owner = &t_gameObject; };

	Component() { };
	virtual ~Component() { };
	virtual void Start() { };
	virtual void Update() { };
	bool Active() { return _active; };
	void SetActive(bool value) { _active = value; };
	virtual void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	virtual void DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager);
};

