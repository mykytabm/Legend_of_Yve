#include "MainMenu.h"
#include "Button.h"
#include "Game.h"



void MainMenu::Update()
{
}

void MainMenu::SetupGameObjects()
{
	sf::Font* font = new sf::Font();
	Button* spriteBtn = new Button();
	this->AddGameObject(spriteBtn);
	font->loadFromFile("../src/Triforce.otf");
	spriteBtn->Sprite("../src/button.png");
	spriteBtn->Text().setFillColor(sf::Color::Black);
	spriteBtn->Text().setString("To Start Screen");
	spriteBtn->Text().setFont(*font);
	sf::Vector2u  windowSize = ServiceLocator::Instance()->GetService<Game>()->Window().getSize();
	spriteBtn->SetPosition(sf::Vector2f(windowSize.x - 30 - spriteBtn->Sprite().getTexture()->getSize().x,
		200 + spriteBtn->Sprite().getTexture()->getSize().y / 2));

	spriteBtn->SetClickListener([this]()->void
		{
		});
}
