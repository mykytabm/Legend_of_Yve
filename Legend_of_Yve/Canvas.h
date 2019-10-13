#pragma once
#include "UIElement.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Canvas : public UIElement
{
private:

public:
	Canvas() {};
	Canvas(std::string t_name);
	~Canvas();
};

