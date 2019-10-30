#pragma once
#include "UIElement.h"
#include "SpriteComponent.h"
#include "Collider.h"
#include <functional>

class Button : public UIElement
{
private:
	bool _pressed = false;
	SpriteComponent _spriteComponent;
	Collider _collider;

	bool MouseClick(int button);
	typedef std::function<void()> OnClickListener;
	OnClickListener onClick;


public:
	void setClickListener(OnClickListener onClickCallBack) { onClick = onClickCallBack; };

	void SetSprite(const std::string t_imagePath) { GetComponent<SpriteComponent>().SetSprite(t_imagePath); };
	sf::Sprite& GetSprite() { return GetComponent<SpriteComponent>().Sprite(); };
	Button();
	~Button();
	void Start() override;
	void Update() override;
};

