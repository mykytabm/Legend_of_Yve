#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game myGame;

	myGame.initialize();

	myGame.run();

	myGame.exit();

	return 0;
}