#pragma once
#include "UIElement.h"
#include "SpriteComponent.h"

class Collider;

class Button :
	public UIElement
{
private:


public:
	void SetSprite(std::string t_imagePath) { GetComponent<SpriteComponent>()->SetSprite(t_imagePath); };
	sf::Sprite* GetSprite() { return GetComponent<SpriteComponent>()->Sprite(); };
	Button();
	~Button();
	void Start() override;
};

