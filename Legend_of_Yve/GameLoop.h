#pragma once
#include "Service.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Component;
class RenderManager;
class Game;

class GameLoop :public Service
{
private:

	std::vector<Component*> _components;

	void update();


public:
	GameLoop();
	~GameLoop();
	void run(bool& t_gameRunning, Game& t_game, RenderManager& t_renderManager);
	void Register(Component* t_component);

	// Inherited via Service
	virtual void initialize() override;


};

