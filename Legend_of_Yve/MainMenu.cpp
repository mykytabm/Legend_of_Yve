#include "MainMenu.h"
#include "Button.h"
#include "Game.h"
#include "Canvas.h"


void MainMenu::Update()
{
}

int availablePoints = 6;
int strengthPoints = 1;
int agilityPoints = 0;
int witsPoints = 1;
void MainMenu::SetupGameObjects()
{
	sf::Vector2u  windowSize = ServiceLocator::Instance()->GetService<Game>()->Window().getSize();


	//character menu;
	Canvas* characterMenuRoot = new Canvas("Character Menu");
	GameObject* background = new GameObject("character menu background");
	background->AddComponent<SpriteComponent>()->Sprite("../src/background.png");
	background->GetComponent<SpriteComponent>()->SetPosition(sf::Vector2f(400, 100));

	Button* cancelBtn = new Button("Cancel Character Menu");

	Button* startGameBtn = new Button("Start Game");

	//character editor buttons




	GameObject* availablePointsText = new GameObject("Available Points");
	availablePointsText->AddComponent<TextComponent>();

	GameObject* strengthPointsText = new GameObject("Strength Points");
	strengthPointsText->AddComponent<TextComponent>();

	Button* addStrengthBtn = new Button("Add Strength");
	Button* subtractStrengthBtn = new Button("Subtract Strength");

	//GameObject* agility = new GameObject;
	//agility->AddComponent<TextComponent>()->Text().setString();

	//GameObject* wits = new GameObject;
	//wits->AddComponent<TextComponent>()->Text().setString();

	//Button* addAgilityBtn = new Button("Add Agility");
	//Button* subtractAgilityBtn = new Button("Subtract Agility");

	//Button* addWitsBtn = new Button("Add Wits");
	//Button* subtractWitsBtn = new Button("Subtract Wits");



	//main menu
	Canvas* menuRoot = new Canvas("Main Menu");
	GameObject* menuBackground = new GameObject("Main Menu Background");
	menuBackground->AddComponent<SpriteComponent>()->Sprite("../src/menu_background.png");
	menuBackground->GetComponent<SpriteComponent>()->Sprite().setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));
	Button* CreateCharacterBtn = new Button("Open Character Menu");
	Button* quitBtn = new Button("Quit");
	Button* eraseDataBtn = new Button("Erase Data");


	characterMenuRoot->AddChild(background);
	characterMenuRoot->AddChild(cancelBtn);
	characterMenuRoot->AddChild(startGameBtn);
	characterMenuRoot->AddChild(availablePointsText);
	characterMenuRoot->AddChild(strengthPointsText);
	characterMenuRoot->AddChild(addStrengthBtn);
	characterMenuRoot->AddChild(subtractStrengthBtn);

	characterMenuRoot->SetActive(false);

	menuRoot->AddChild(CreateCharacterBtn);
	menuRoot->AddChild(eraseDataBtn);
	menuRoot->AddChild(quitBtn);

	AddGameObject(characterMenuRoot);
	AddGameObject(menuRoot);

	//order matters: layers form from top to bottom
	AddGameObject(menuBackground);
	AddGameObject(CreateCharacterBtn);
	AddGameObject(quitBtn);
	AddGameObject(eraseDataBtn);
	AddGameObject(background);
	AddGameObject(cancelBtn);
	AddGameObject(startGameBtn);
	AddGameObject(availablePointsText);
	AddGameObject(strengthPointsText);
	AddGameObject(addStrengthBtn);
	AddGameObject(subtractStrengthBtn);


	availablePointsText->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	availablePointsText->GetComponent<TextComponent>()->Text().setFillColor(sf::Color::Black);
	availablePointsText->GetComponent<TextComponent>()->Text().
		setString("Available points: " + std::to_string(availablePoints));
	availablePointsText->GetComponent<TextComponent>()->Text().setPosition(sf::Vector2f(410, 100));

	strengthPointsText->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	strengthPointsText->GetComponent<TextComponent>()->Text().setFillColor(sf::Color::Black);
	strengthPointsText->GetComponent<TextComponent>()->Text().setString("Strength: " + std::to_string(strengthPoints));
	strengthPointsText->GetComponent<TextComponent>()->Text().setPosition(sf::Vector2f(410, 130));

	addStrengthBtn->Sprite("../src/add.png");
	addStrengthBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)addStrengthBtn->Sprite().getTexture()->getSize());
	addStrengthBtn->SetPosition(sf::Vector2f(570, 139));

	addStrengthBtn->SetClickListener([this]()->void
		{
			if (availablePoints > 0)
			{
				availablePoints--;
				strengthPoints++;
				GetGameObject("Strength Points")->GetComponent<TextComponent>()->
					Text().setString("Strength: " + std::to_string(strengthPoints));
				GetGameObject("Available Points")->GetComponent<TextComponent>()->
					Text().setString("Available points: " + std::to_string(availablePoints));
			}
		});

	subtractStrengthBtn->Sprite("../src/subtract.png");
	subtractStrengthBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)subtractStrengthBtn->Sprite().getTexture()->getSize());
	subtractStrengthBtn->SetPosition(sf::Vector2f(600, 139));

	subtractStrengthBtn->SetClickListener([this]()->void
		{
			if (availablePoints < 6)
			{
				availablePoints++;
				strengthPoints--;
				GetGameObject("Strength Points")->GetComponent<TextComponent>()->
					Text().setString("Strength: " + std::to_string(strengthPoints));
				GetGameObject("Available Points")->GetComponent<TextComponent>()->
					Text().setString("Available points: " + std::to_string(availablePoints));
			}
		});


	cancelBtn->Sprite("../src/small_button.png");
	cancelBtn->Text().setFillColor(sf::Color::White);
	cancelBtn->Text().setString("Cancel");
	cancelBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)cancelBtn->Sprite().getTexture()->getSize());
	cancelBtn->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	cancelBtn->SetPosition(sf::Vector2f(410, 440));

	cancelBtn->SetClickListener([this]()->void
		{
			GetGameObject("Character Menu")->SetActive(false);
			GetGameObject("Main Menu")->SetActive(true);
		});


	startGameBtn->Sprite("../src/small_button.png");
	startGameBtn->Text().setFillColor(sf::Color::White);
	startGameBtn->Text().setString("Start Game!");
	startGameBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)startGameBtn->Sprite().getTexture()->getSize());
	startGameBtn->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	startGameBtn->SetPosition(sf::Vector2f(770, 440));

	startGameBtn->SetClickListener([this]()->void
		{

		});


	CreateCharacterBtn->Sprite("../src/button.png");
	CreateCharacterBtn->Text().setFillColor(sf::Color::White);
	CreateCharacterBtn->Text().setString("Create Character");
	CreateCharacterBtn->GetComponent<Collider>()->SetSize((sf::Vector2f)CreateCharacterBtn->Sprite().getTexture()->getSize());
	CreateCharacterBtn->GetComponent<TextComponent>()->Font("../src/Arial.ttf");
	CreateCharacterBtn->SetPosition(sf::Vector2f(
		windowSize.x - 30 - CreateCharacterBtn->Sprite().getTexture()->getSize().x,
		200 + CreateCharacterBtn->Sprite().getTexture()->getSize().y / 2)
	);

	CreateCharacterBtn->SetClickListener([this]()->void
		{
			std::cout << "play clicked" << std::endl;
			GetGameObject("Character Menu")->SetActive(true);
			GetGameObject("Main Menu")->SetActive(false);

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
