#include "StartScreen.h"
#include "GameObject.h"
#include "Button.h"
#include "ServiceLocator.h"
#include "Game.h"

StartScreen::StartScreen(std::string t_id)
{
	_id = t_id;
}

void StartScreen::initialize()
{
	Button* spriteBtn = new Button();
	this->AddGameObject(spriteBtn);
	spriteBtn->SetSprite("../src/button.png");
	//spriteBtn->GetSprite().setScale(0.5f, 0.5f);
	sf::Vector2u  windowSize = ServiceLocator::instance()->GetService<Game>()->Window().getSize();
	spriteBtn->SetPosition(sf::Vector2f(windowSize.x/2-spriteBtn->GetSprite().getTexture()->getSize().x/2,
		windowSize.y / 2 - spriteBtn->GetSprite().getTexture()->getSize().y / 2));
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



