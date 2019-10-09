#pragma once
#include <SFML/Graphics.hpp>
#include "FPSCounter.h"
class Game
{
private:
	sf::RenderWindow* m_window;

public:
	Game();
	~Game();
	sf::RenderWindow* getWindow() { return m_window; }
	void initializeWindow();
	void initialize();
	void run();
	void exit();
};

