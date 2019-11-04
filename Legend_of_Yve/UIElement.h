#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class UIElement : public GameObject
{
private:

protected:

public:
	UIElement() { };
	UIElement( const std::string t_name);
	~UIElement();
};

