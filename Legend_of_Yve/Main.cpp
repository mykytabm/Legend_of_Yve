#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{

	Game game;

	game.initialize();
	game.run();
	game.exit();

	return 0;
}