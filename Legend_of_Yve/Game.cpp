#include "Game.h"
#include "GameObject.h"
#include "StartScreen.h"
#include "ServiceLocator.h"

void Game::InitializeServices()
{
	m_gameLoop = new GameLoop();
	m_renderManager = new RenderManager();
	m_sceneManager = new SceneManager();

	ServiceLocator::instance()->AddService(this);
	//ServiceLocator::instance()->AddService(m_gameLoop);
	//ServiceLocator::instance()->AddService(m_renderManager);
	//ServiceLocator::instance()->AddService(m_sceneManager);

	/*m_renderManager->initialize();
	m_gameLoop->initialize();
	m_sceneManager->initialize();*/

}

Game::Game() : m_sceneManager(nullptr),
m_gameLoop(nullptr), m_renderManager(nullptr), m_gameRunning(false)
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

	m_sceneManager->LoadScene(startScreen);
	m_gameWindowRef = m_renderManager->GameWindow();
}

void Game::ProcessEvents()
{

	sf::Event event;
	while (m_gameWindowRef->pollEvent(event))
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
	m_gameLoop->run(m_gameRunning);

	// GameLoop->run()
	//   GameLoop->Update();
	//   RenderManager->Render();
	//   Game->ProccessEvents();
	//
	//

}

void Game::exit()
{
	if (m_gameWindowRef->isOpen()) {
		m_gameRunning = false;
		m_gameWindowRef->close();
	}
}

