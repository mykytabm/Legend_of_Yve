#pragma once
#include "Service.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Component;
class RenderManager;

class GameLoop :public Service
{
private:

	std::vector<Component>* m_components;
	RenderManager* m_renderManager;

	void update();


public:
	GameLoop();
	~GameLoop();
	void run(sf::Window& t_window);


	// Inherited via Service
	virtual void initialize() override;

};

