#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameLoop.h"
#include "RenderManager.h"
#include "Service.h"

class Game : public Service
{
private:
	sf::RenderWindow _gameWindow;
	RenderManager _renderManager;
	SceneManager _sceneManager;
	GameLoop _gameLoop;
	bool _gameRunning;
	void InitializeServices();

public:
	Game();
	~Game();

	sf::RenderWindow& Window() { return _gameWindow; }
	bool& GameRunning();

	void ProcessEvents();
	void Initialize(std::list<Scene*> t_scenes);
	void Run();
	void Exit();
};

