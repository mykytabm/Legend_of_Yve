#pragma once

class GameObject;
class GameLoop;
class RenderManager;

class Component
{
private:
protected:
	bool _active = true;
	GameObject* _owner;
public:
	void SetGameObject(GameObject* t_gameObject) { _owner = t_gameObject; };

	Component() { };
	virtual ~Component() { };
	virtual void Start() { };
	virtual void Update() { };
	bool Active() { return _active; };
	void SetActive(bool value);
	virtual void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	virtual void DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager);
};

