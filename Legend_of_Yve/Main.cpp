#include <SFML/Graphics.hpp>
#include "Game.h"
#include "StartScreen.h"
#include "Scene.h"
#include <list>
int main()
{
	Game game;
	StartScreen startScreen = StartScreen("MainMenu");

	std::list<Scene*> yveGameScenes = { &startScreen };


	game.initialize(yveGameScenes);
	game.run();
	game.exit();


	return 0;
}