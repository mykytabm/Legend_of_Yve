#include "StartScreen.h"
#include "GameObject.h"
#include "SpriteDrawableComponent.h"

StartScreen::StartScreen(std::string t_id)
{
	m_id = t_id;
}

void StartScreen::initialize()
{
	GameObject* text = new GameObject("Text");
	text->AddComponent(new SpriteDrawableComponent());
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



