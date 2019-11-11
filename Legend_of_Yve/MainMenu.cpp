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


	//character menu;
	Canvas* characterMenuRoot = new Canvas("Character Menu");
	GameObject* background = new GameObject("character menu background");
	background->AddComponent<SpriteComponent>()->Sprite("../src/background.png");
	background->GetComponent<SpriteComponent>()->SetPosition(sf::Vector2f(400, 100));

	Button* cancelBtn = new Button("Cancel Character Menu");

	//main menu
	Canvas* menuRoot = new Canvas("Main Menu");
	GameObject* menuBackground = new GameObject("Main Menu Background");
	menuBackground->AddComponent<SpriteComponent>()->Sprite("../src/menu_background.png");
	menuBackground->GetComponent<SpriteComponent>()->Sprite().setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));
	Button* playBtn = new Button("Play");
	Button* quitBtn = new Button("Quit");
	Button* eraseDataBtn = new Button("Erase Data");


	characterMenuRoot->AddChild(background);
	characterMenuRoot->AddChild(cancelBtn);

	characterMenuRoot->SetActive(false);


	menuRoot->AddChild(playBtn);
	menuRoot->AddChild(eraseDataBtn);
	menuRoot->AddChild(quitBtn);

	this->AddGameObject(characterMenuRoot);
	this->AddGameObject(menuRoot);

	//order matters: layers form from top to bottom
	this->AddGameObject(menuBackground);
	this->AddGameObject(playBtn);
	this->AddGameObject(quitBtn);
	this->AddGameObject(eraseDataBtn);
	this->AddGameObject(background);
	this->AddGameObject(cancelBtn);






	cancelBtn->Sprite("../src/small_button.png");
	cancelBtn->Text().setFillColor(sf::Color::White);
	cancelBtn->Text().setString("Cancel");
	cancelBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)cancelBtn->Sprite().getTexture()->getSize());
	cancelBtn->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	cancelBtn->SetPosition(sf::Vector2f(410, 440));

	cancelBtn->SetClickListener([this]()->void
		{
			this->GetGameObject("Character Menu")->SetActive(false);
			this->GetGameObject("Main Menu")->SetActive(true);
		});


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
			std::cout << "play clicked" << std::endl;
			this->GetGameObject("Character Menu")->SetActive(true);
			this->GetGameObject("Main Menu")->SetActive(false);

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
			ServiceLocator::Instance()->GetService<Game>()->Exit();
		});



}
