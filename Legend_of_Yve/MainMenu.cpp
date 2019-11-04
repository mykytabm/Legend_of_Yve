#include "MainMenu.h"
#include "Button.h"
#include "Game.h"



void MainMenu::Update()
{
}

void MainMenu::SetupGameObjects()
{
	sf::Vector2u  windowSize = ServiceLocator::Instance()->GetService<Game>()->Window().getSize();

	sf::Font* font = new sf::Font();
	Button* playBtn = new Button();
	this->AddGameObject(playBtn);
	font->loadFromFile("../src/Triforce.otf");
	playBtn->Sprite("../src/button.png");
	playBtn->Text().setFillColor(sf::Color::Black);
	playBtn->Text().setString("Play");
	playBtn->Text().setFont(*font);
	playBtn->SetPosition(sf::Vector2f(windowSize.x - 30 - playBtn->Sprite().getTexture()->getSize().x,
		200 + playBtn->Sprite().getTexture()->getSize().y / 2));

	playBtn->SetClickListener([this]()->void
		{

		});

	Button* eraseDataBtn = new Button();
	this->AddGameObject(eraseDataBtn);
	font->loadFromFile("../src/Triforce.otf");
	eraseDataBtn->Sprite("../src/button.png");
	eraseDataBtn->Text().setFillColor(sf::Color::Black);
	eraseDataBtn->Text().setString("Erase Data");
	eraseDataBtn->Text().setFont(*font);
	eraseDataBtn->SetPosition(sf::Vector2f(windowSize.x - 30 - eraseDataBtn->Sprite().getTexture()->getSize().x,
		270 + eraseDataBtn->Sprite().getTexture()->getSize().y / 2));

	eraseDataBtn->SetClickListener([this]()->void
		{

		});

	Button* quitBtn = new Button();
	this->AddGameObject(quitBtn);
	font->loadFromFile("../src/Triforce.otf");
	quitBtn->Sprite("../src/button.png");
	quitBtn->Text().setFillColor(sf::Color::Black);
	quitBtn->Text().setString("Quit");
	quitBtn->Text().setFont(*font);
	quitBtn->SetPosition(sf::Vector2f(windowSize.x - 30 - quitBtn->Sprite().getTexture()->getSize().x,
		340 + quitBtn->Sprite().getTexture()->getSize().y / 2));

	quitBtn->SetClickListener([this]()->void
		{

		});

}
