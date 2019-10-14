#pragma once
#include "UIElement.h"
#include "SpriteComponent.h"
#include "Collider.h"

class Button : public UIElement
{
private:
	SpriteComponent m_spriteComponent;
	Collider m_collider;


public:
	void SetSprite(const std::string t_imagePath) { GetComponent<SpriteComponent>().SetSprite(t_imagePath); };
	sf::Sprite& GetSprite() { return GetComponent<SpriteComponent>().Sprite(); };
	Button();
	~Button();
	void Start() override;
};

