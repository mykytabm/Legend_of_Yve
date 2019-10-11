#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GameLoop.h"
#include "RenderManager.h"
#include "Service.h"

class Game : public Service
{
private:

	SceneManager* m_sceneManager;
	GameLoop* m_gameLoop;
	RenderManager* m_renderManager;
	void InitializeServices();
	bool m_gameRunning;
	sf::RenderWindow* m_gameWindowRef;

public:
	Game();
	~Game();
	bool& GameRunning()  { return m_gameRunning; };
	void ProcessEvents();
	void run();
	void exit();

	// Inherited via Service
	virtual void initialize() override;
};

