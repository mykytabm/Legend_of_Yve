#include "Game.h"
#include "GameObject.h"
#include "StartScreen.h"
#include "ServiceLocator.h"
#include <iostream>
#include <memory>
void Game::InitializeServices()
{

	ServiceLocator::Instance()->AddService(*this);
	ServiceLocator::Instance()->AddService(_gameLoop);
	ServiceLocator::Instance()->AddService(_renderManager);
	ServiceLocator::Instance()->AddService(_sceneManager);

	_renderManager.Initialize();
	_gameLoop.Initialize();
	_sceneManager.Initialize();

}

Game::Game() : _gameWindow(sf::VideoMode(1280, 720), "Legend Of Yve"), _renderManager(&_gameWindow)
{
}

Game::~Game()
{

}

bool& Game::GameRunning()
{
	return _gameRunning;
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_gameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			Exit();
		}
		else
		{
			//proccess Scene events
		}
	}

}

void Game::Run()
{
	_gameLoop.Run(_gameRunning, *this, _renderManager);

}

void Game::Exit()
{
	if (_gameWindow.isOpen()) {
		_gameWindow.close();
		_gameRunning = false;
	}
}

void Game::Initialize(std::list<Scene*> t_scenes)
{
	InitializeServices();
	_sceneManager.SetScenes(t_scenes);
	_sceneManager.LoadScene(t_scenes.front());
	_gameRunning = true;
}

