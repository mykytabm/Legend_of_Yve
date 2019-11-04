#include "StartScreen.h"
#include "GameObject.h"
#include "Button.h"
#include "ServiceLocator.h"
#include "Game.h"

void StartScreen::SetupGameObjects()
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("../src/Arial.ttf");
	Button* spriteBtn = new Button();
	this->AddGameObject(spriteBtn);
	spriteBtn->Sprite("../src/button.png");
	spriteBtn->Text().setString("To Main Menu");
	spriteBtn->Text().setFillColor(sf::Color::White);
	spriteBtn->Text().setFont(*font);
	sf::Vector2u  windowSize = ServiceLocator::Instance()->GetService<Game>()->Window().getSize();
	spriteBtn->SetPosition(sf::Vector2f(windowSize.x / 2 - spriteBtn->Sprite().getTexture()->getSize().x / 2,
		windowSize.y / 2 - spriteBtn->Sprite().getTexture()->getSize().y / 2));

	spriteBtn->SetClickListener([this]()->void
		{
			ServiceLocator::Instance()->GetService<SceneManager>()->LoadScene("MainMenu");
			std::cout << "Button was clicked" << std::endl;
		});
}





StartScreen::~StartScreen()
{

}

void StartScreen::Update()
{

}




