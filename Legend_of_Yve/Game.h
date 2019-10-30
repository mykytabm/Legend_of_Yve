#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameLoop.h"
#include "RenderManager.h"
#include "Service.h"

class Game : public Service
{
private:

	SceneManager _sceneManager;
	GameLoop _gameLoop;
	RenderManager _renderManager;
	void InitializeServices();
	bool _gameRunning;

	sf::RenderWindow _gameWindow;

public:
	sf::RenderWindow& Window() { return _gameWindow; };
	Game();
	~Game();
	bool& GameRunning() { return _gameRunning; };
	void ProcessEvents();
	void run();
	void exit();

	// Inherited via Service
	virtual void initialize() override;
};

