#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
class Game
{
private:
	sf::RenderWindow* m_window;
	SceneManager* m_sceneManager;
public:
	Game();
	~Game();
	sf::RenderWindow* getWindow() { return m_window; }
	void initializeWindow();
	void initialize();
	void ProccessEvents();
	void run();
	void exit();
};

