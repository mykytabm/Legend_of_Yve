#pragma once
#include "UIElement.h"
#include "SpriteComponent.h"

class Button :
	public UIElement
{
private:
	SpriteComponent* m_sprite;

public:

	Button();
	~Button();
	void Start() override;
};

