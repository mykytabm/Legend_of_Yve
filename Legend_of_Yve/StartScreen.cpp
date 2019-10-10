#include "StartScreen.h"
#include "GameObject.h"
#include "Renderer.h"


StartScreen::StartScreen(std::string t_id)
{
	m_id = t_id;
}

void StartScreen::initialize()
{
	GameObject* text = new GameObject("Text");
	AddGameObject(text);
	Renderer* renderer = new Renderer();
}




StartScreen::~StartScreen()
{
}

void StartScreen::update()
{
}

void StartScreen::render(sf::RenderWindow& t_window)
{
}



