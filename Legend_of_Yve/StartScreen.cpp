#include "StartScreen.h"
#include "GameObject.h"
#include "Button.h"
StartScreen::StartScreen(std::string t_id)
{
	m_id = t_id;
}

void StartScreen::initialize()
{
	Button* spriteBtn = new Button();
	this->AddGameObject(spriteBtn);
	spriteBtn->SetSprite("../Assets/Sprite_logo.jpg");
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



