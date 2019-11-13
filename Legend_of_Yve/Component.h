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
	virtual ~Component() { };

	bool Active() const;

	void SetGameObject(GameObject* t_gameObject);
	void SetActive(bool value);
	virtual void Register(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	virtual void DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager);
	virtual void Start() = 0;
	virtual void Update() = 0;
};

