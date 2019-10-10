#include "Game.h"
#include "GameObject.h"
#include "StartScreen.h"
Game::Game() :m_window(nullptr), m_sceneManager(nullptr)
{

}

Game::~Game()
{
	m_window = nullptr;
}

void Game::initializeWindow()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Legend Of Yve");
}

void Game::initialize()
{
	initializeWindow();
	///init game loop
	//init renderer
	m_sceneManager = new SceneManager();

	StartScreen* startScreen = new StartScreen("welcome screen");

	m_sceneManager->LoadScene(startScreen);




}

void Game::run()
{

	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				m_window->close();
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
				m_window->close();
			}
		}
		m_window->clear();





		m_window->display();
	}
}

void Game::exit()
{
	if (m_window->isOpen()) {
		m_window->close();
	}
}
