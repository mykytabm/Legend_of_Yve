#pragma once
#include "UIElement.h"
#include "SpriteComponent.h"
#include "TextComponent.h"
#include "Collider.h"
#include <functional>

class Button : public UIElement
{

private:
	SpriteComponent _spriteComponent;
	TextComponent _textComponent;
	Collider _collider;

	bool _pressed = false;

	bool MouseClick(int button);

	typedef std::function<void()> OnClickListener;
	OnClickListener onClick;


public:
	Button(std::string t_name);
	~Button();

	sf::Sprite& Sprite();
	sf::Text& Text();

	void SetClickListener(OnClickListener onClickCallBack);
	void Sprite(const std::string t_imagePath);
	void Start() override;
	void Update() override;
};

