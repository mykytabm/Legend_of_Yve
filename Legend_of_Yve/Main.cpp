#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game myGame;

	myGame.initialize();
	myGame.run();
	//TODO: exit in exit method and not in run method
	myGame.exit();

	return 0;
}