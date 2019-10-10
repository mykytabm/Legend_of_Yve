#pragma once
#include "Scene.h"
#include <string>

class StartScreen :public Scene
{
public:
	StartScreen(std::string t_id);

	~StartScreen();

	// Inherited via Scene
	virtual void update();
	virtual void render(sf::RenderWindow& t_window);
	virtual void AddGameObject(GameObject* t_GameObject);
	virtual void initialize() override;
};

