#pragma once
#include "Service.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Component;
class RenderManager;
class Game;
class GameObject;

class GameLoop :public Service
{
private:
	std::vector<GameObject*> _gameObjects;
	std::vector<Component*> _components;

	void Update();
public:
	GameLoop();
	~GameLoop();

	bool Contains(GameObject* t_gameObject);
	bool Contains(Component* t_component);

	void Run(bool& t_gameRunning, Game& t_game, RenderManager& t_renderManager);
	void Register(Component* t_component);
	void Register(GameObject* t_gameObject);
	void DeRegister(GameObject* t_gameObject);
	void DeRegister(Component* t_component);

	virtual void Initialize() override;

};

