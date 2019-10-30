#include "Game.h"
#include "GameObject.h"
#include "StartScreen.h"
#include "ServiceLocator.h"
#include <iostream>
#include <memory>
void Game::InitializeServices()
{

	ServiceLocator::instance()->AddService(*this);
	ServiceLocator::instance()->AddService(_gameLoop);
	ServiceLocator::instance()->AddService(_renderManager);
	ServiceLocator::instance()->AddService(_sceneManager);

	_renderManager.initialize();
	_gameLoop.initialize();
	_sceneManager.initialize();

}

Game::Game() : _gameWindow(sf::VideoMode(1280, 720), "Legend Of Yve"), _renderManager(&_gameWindow)
{
}

Game::~Game()
{

}


void Game::initialize()
{

	InitializeServices();

	_gameRunning = true;


	StartScreen* startScreen = new StartScreen("welcome screen");

	_sceneManager.LoadScene(startScreen);

}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_gameWindow.pollEvent(event))
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
	_gameLoop.run(_gameRunning, *this, _renderManager);

}

void Game::exit()
{
	if (_gameWindow.isOpen()) {
		_gameWindow.close();
		_gameRunning = false;
	}
}

