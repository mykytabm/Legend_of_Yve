#include "Game.h"
#include "GameObject.h"
#include "StartScreen.h"
#include "ServiceLocator.h"
#include <iostream>
#include <memory>
void Game::InitializeServices()
{

	ServiceLocator::instance()->AddService(*this);
	ServiceLocator::instance()->AddService(m_gameLoop);
	ServiceLocator::instance()->AddService(m_renderManager);
	ServiceLocator::instance()->AddService(m_sceneManager);

	m_renderManager.initialize();
	m_gameLoop.initialize();
	m_sceneManager.initialize();

}

Game::Game() : m_gameWindow(sf::VideoMode(1280, 720), "Legend Of Yve"), m_renderManager(&m_gameWindow)
{
}

Game::~Game()
{

}


void Game::initialize()
{

	InitializeServices();

	m_gameRunning = true;


	StartScreen* startScreen = new StartScreen("welcome screen");

	m_sceneManager.LoadScene(startScreen);

}

void Game::ProcessEvents()
{
	sf::Event event;
	while (m_gameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			exit();
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
			exit();
		}
	}

}

void Game::run()
{
	m_gameLoop.run(m_gameRunning, *this, m_renderManager);

}

void Game::exit()
{
	if (m_gameWindow.isOpen()) {
		//delete m_sceneManager;
		//delete m_renderManager;
		//delete m_gameLoop;
		m_gameWindow.close();
		//delete m_gameWindow;
		m_gameRunning = false;
	}
}

