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

	std::vector<Component>* m_components;
	RenderManager* m_renderManager;
	Game* m_game;
	void update();


public:
	GameLoop();
	~GameLoop();
	void run(bool& t_gameRunning);


	// Inherited via Service
	virtual void initialize() override;

};

