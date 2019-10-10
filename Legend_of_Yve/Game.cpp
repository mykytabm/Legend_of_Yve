#include "Game.h"
#include "GameObject.h"
#include "StartScreen.h"
#include "ServiceLocator.h"

void Game::InitializeServices()
{
	m_gameLoop = new GameLoop();
	m_renderManager = new RenderManager();
	m_sceneManager = new SceneManager();

	ServiceLocator::instance()->AddService(m_gameLoop);
	ServiceLocator::instance()->AddService(m_renderManager);
	ServiceLocator::instance()->AddService(m_sceneManager);

	m_gameLoop->initialize();
	m_renderManager->initialize();
	m_sceneManager->initialize();

}

Game::Game() :m_window(nullptr), m_sceneManager(nullptr),
m_gameLoop(nullptr), m_renderManager(nullptr)
{

}

Game::~Game()
{

}

void Game::initializeWindow()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Legend Of Yve");
}

void Game::initialize()
{
	initializeWindow();

	InitializeServices();



	StartScreen* startScreen = new StartScreen("welcome screen");

	m_sceneManager->LoadScene(startScreen);
}

void Game::ProccessEvents()
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

}

void Game::run()
{
	//should only contain GameLoop-> run();

	// GameLoop->run()
	//   GameLoop->Update();
	//   RenderManager->Render();
	//   Game->ProccessEvents();
	//
	//
	while (m_window->isOpen())
	{


		m_window->clear();


		m_window->display();


		ProccessEvents();
	}
}

void Game::exit()
{
	if (m_window->isOpen()) {
		m_window->close();
	}
}

