#include "StartScreen.h"
#include "GameObject.h"
#include "ImageComponent.h"

StartScreen::StartScreen(std::string t_id)
{
	m_id = t_id;
}

void StartScreen::initialize()
{
	GameObject* text = new GameObject("Text");
	text->AddComponent(new ImageComponent());
	AddGameObject(text);
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



