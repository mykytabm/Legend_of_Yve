#include "FPSCounter.h"
#include <iostream>


FPSCounter::FPSCounter()
{
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setString("FPS: ");
	text.setFillColor(sf::Color::Green);
	text.setPosition(sf::Vector2f(10, 0));
}

FPSCounter::~FPSCounter() { }

void FPSCounter::render(sf::RenderWindow& window)
{
	window.draw(text);
}

void FPSCounter::update(sf::Time elapsed)
{
	float milliseconds = elapsed.asMilliseconds();
	float fps = 1.0f / (milliseconds != 0 ? milliseconds : 0.01666f);
	std::cout << fps << std::endl;
	text.setString("FPS: " + std::to_string(fps));
}
