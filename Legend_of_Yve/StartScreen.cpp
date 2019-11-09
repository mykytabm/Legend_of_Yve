#include "StartScreen.h"
#include "GameObject.h"
#include "Button.h"
#include "ServiceLocator.h"
#include "Game.h"

void StartScreen::SetupGameObjects()
{
	sf::Vector2u  windowSize = ServiceLocator::Instance()->GetService<Game>()->Window().getSize();

	Button* startBtn = new Button();
	startBtn->GetComponent<TextComponent>().Font("../src/Arial.ttf");
	startBtn->GetComponent<SpriteComponent>().Sprite("../src/button.png");
	startBtn->GetComponent<TextComponent>().Text().setString("Start");
	startBtn->GetComponent<TextComponent>().Text().setFillColor(sf::Color::White);
	startBtn->SetPosition(sf::Vector2f(
		windowSize.x / 2 - startBtn->Sprite().getTexture()->getSize().x / 2,
		windowSize.y / 2 - startBtn->Sprite().getTexture()->getSize().y / 2
	));

	startBtn->SetClickListener([this]()->void
		{
			ServiceLocator::Instance()->GetService<SceneManager>()->LoadScene("MainMenu");
			std::cout << "Button was clicked" << std::endl;
		});

	this->AddGameObject(startBtn);

}

StartScreen::~StartScreen()
{
	for (auto go : _gameObjects)
	{
		delete go;
	}
	_gameObjects.clear();
}





