#include <list>
#include "Game.h"
#include "StartScreen.h"
#include "FightScreen.h"
#include "MainMenu.h"
int main()
{
	Game game;

	MainMenu menu("Main Menu");
	FightScreen fightScreen("Fight Screen");

	std::list<Scene*> yveGameScenes = { &menu,&fightScreen };
	game.Initialize(yveGameScenes);
	game.Run();
	game.Exit();

	return 0;
}