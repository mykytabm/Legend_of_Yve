#include "MainMenu.h"
#include "Button.h"
#include "Game.h"
#include "Canvas.h"


void MainMenu::Update()
{
}

void MainMenu::SetupGameObjects()
{
	sf::Vector2u  windowSize = ServiceLocator::Instance()->GetService<Game>()->Window().getSize();


	Canvas* c = new Canvas();

	Button* playBtn = new Button();

	playBtn->Sprite("../src/button.png");
	playBtn->Text().setFillColor(sf::Color::White);
	playBtn->Text().setString("Start Game");
	playBtn->GetComponent<TextComponent>().Font("../src/Arial.ttf");
	playBtn->SetPosition(sf::Vector2f(
		windowSize.x - 30 - playBtn->Sprite().getTexture()->getSize().x,
		200 + playBtn->Sprite().getTexture()->getSize().y / 2)
	);

	playBtn->SetClickListener([this]()->void
		{

		});

	Button* eraseDataBtn = new Button();
	eraseDataBtn->Sprite("../src/button.png");
	eraseDataBtn->Text().setFillColor(sf::Color::White);
	eraseDataBtn->Text().setString("Erase Data");
	eraseDataBtn->GetComponent<TextComponent>().Font("../src/Arial.ttf");
	eraseDataBtn->SetPosition(sf::Vector2f(windowSize.x - 30 - eraseDataBtn->Sprite().getTexture()->getSize().x,
		270 + eraseDataBtn->Sprite().getTexture()->getSize().y / 2));

	eraseDataBtn->SetClickListener([this]()->void
		{

		});

	Button* quitBtn = new Button();

	quitBtn->Sprite("../src/button.png");
	quitBtn->Text().setFillColor(sf::Color::White);
	quitBtn->Text().setString("Quit");
	quitBtn->GetComponent<TextComponent>().Font("../src/Arial.ttf");
	quitBtn->SetPosition(sf::Vector2f(
		windowSize.x - 30 - quitBtn->Sprite().getTexture()->getSize().x,
		340 + quitBtn->Sprite().getTexture()->getSize().y / 2)
	);

	quitBtn->SetClickListener([this]()->void
		{

		});

	this->AddGameObject(playBtn);
	this->AddGameObject(eraseDataBtn);
	this->AddGameObject(quitBtn);
}
