#include "StartScreen.h"
#include "GameObject.h"
#include "Button.h"
#include "ServiceLocator.h"
#include "Game.h"


void StartScreen::Initialize()
{
	SetupGameObjects();
}

void Click()
{
	std::cout << "Hello" << std::endl;
}
void StartScreen::SetupGameObjects()
{
	Button* spriteBtn = new Button();
	this->AddGameObject(spriteBtn);
	spriteBtn->SetSprite("../src/button.png");

	sf::Vector2u  windowSize = ServiceLocator::Instance()->GetService<Game>()->Window().getSize();
	spriteBtn->SetPosition(sf::Vector2f(windowSize.x / 2 - spriteBtn->GetSprite().getTexture()->getSize().x / 2,
		windowSize.y / 2 - spriteBtn->GetSprite().getTexture()->getSize().y / 2));

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




