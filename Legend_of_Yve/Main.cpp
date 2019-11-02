#include <SFML/Graphics.hpp>
#include "Game.h"
#include "StartScreen.h"
#include "Scene.h"
#include <list>
int main()
{
	Game game;
	StartScreen startScreen = StartScreen("MainMenu");
	StartScreen startScreen1 = StartScreen("MainMenu1");


	std::list<Scene*> yveGameScenes = { &startScreen,&startScreen1 };


	game.initialize(yveGameScenes);
	game.run();
	game.exit();


	return 0;
}