#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameLoop.h"
#include "RenderManager.h"
#include "Service.h"

class Game: public Service
{
private:
	sf::RenderWindow* m_window;
	SceneManager* m_sceneManager;
	GameLoop* m_gameLoop;
	RenderManager* m_renderManager;
	void InitializeServices();
public:
	Game();
	~Game();
	sf::RenderWindow* getWindow() { return m_window; }
	void initializeWindow();
	void ProccessEvents();
	void run();
	void exit();

	// Inherited via Service
	virtual void initialize() override;
};

