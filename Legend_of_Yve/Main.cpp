#include <SFML/Graphics.hpp>
#include "Game.h"
#include "StartScreen.h"
#include "MainMenu.h"
#include "Scene.h"
#include <list>
int main()
{
	Game game;



	StartScreen startScreen("StartScreen");
	MainMenu menu("MainMenu");


	std::list<Scene*> yveGameScenes = { &startScreen,&menu };


	game.Initialize(yveGameScenes);
	game.Run();
	game.Exit();


	return 0;
}