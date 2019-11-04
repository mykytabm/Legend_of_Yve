#pragma once
#include "UIElement.h"
#include "SpriteComponent.h"
#include "TextComponent.h"
#include "Collider.h"
#include <functional>

class Button : public UIElement
{
private:
	bool _pressed = false;
	SpriteComponent _spriteComponent;
	TextComponent _textComponent;
	Collider _collider;


	bool MouseClick(int button);
	typedef std::function<void()> OnClickListener;
	OnClickListener onClick;


public:
	void SetClickListener(OnClickListener onClickCallBack) { onClick = onClickCallBack; };

	void Sprite(const std::string t_imagePath) { _spriteComponent.Sprite(t_imagePath); };
	sf::Sprite& Sprite() { return _spriteComponent.Sprite(); };
	sf::Text& Text() { return _textComponent.Text(); };
	Button();
	~Button();
	void Start() override;
	void Update() override;
};

