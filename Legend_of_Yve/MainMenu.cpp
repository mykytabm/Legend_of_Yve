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

	Canvas* c = new Canvas("Menu");
	Button* playBtn = new Button("Play");
	Button* quitBtn = new Button("Quit");
	Button* eraseDataBtn = new Button("Erase Data");


	playBtn->Sprite("../src/button.png");
	playBtn->Text().setFillColor(sf::Color::White);
	playBtn->Text().setString("Start Game");
	playBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)playBtn->Sprite().getTexture()->getSize());
	playBtn->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	playBtn->SetPosition(sf::Vector2f(
		windowSize.x - 30 - playBtn->Sprite().getTexture()->getSize().x,
		200 + playBtn->Sprite().getTexture()->getSize().y / 2)
	);

	playBtn->SetClickListener([this]()->void
		{
			this->GetGameObject("Menu")->SetActive(!this->GetGameObject("Menu")->Active());
		});

	eraseDataBtn->Sprite("../src/button.png");
	eraseDataBtn->Text().setFillColor(sf::Color::White);
	eraseDataBtn->Text().setString("Erase Data");
	eraseDataBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)eraseDataBtn->Sprite().getTexture()->getSize());
	eraseDataBtn->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	eraseDataBtn->SetPosition(sf::Vector2f(windowSize.x - 30 - eraseDataBtn->Sprite().getTexture()->getSize().x,
		270 + eraseDataBtn->Sprite().getTexture()->getSize().y / 2));

	eraseDataBtn->SetClickListener([this]()->void
		{
			std::cout << "Erase Data button click" << std::endl;
		});


	quitBtn->Sprite("../src/button.png");
	quitBtn->Text().setFillColor(sf::Color::White);
	quitBtn->Text().setString("Quit");
	quitBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)quitBtn->Sprite().getTexture()->getSize());
	quitBtn->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	quitBtn->SetPosition(sf::Vector2f(
		windowSize.x - 30 - quitBtn->Sprite().getTexture()->getSize().x,
		340 + quitBtn->Sprite().getTexture()->getSize().y / 2)
	);

	quitBtn->SetClickListener([this]()->void
		{
			std::cout << "Quit button click" << std::endl;
		});

	c->AddChild(eraseDataBtn);

	this->AddGameObject(c);
	this->AddGameObject(playBtn);
	this->AddGameObject(eraseDataBtn);
	this->AddGameObject(quitBtn);
}
