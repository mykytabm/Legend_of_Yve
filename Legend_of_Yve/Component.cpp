#include "Component.h"
#include "GameLoop.h"

void Component::Register(GameLoop* t_gameLoop, RenderManager* t_renderManager)
{
	t_gameLoop->Register(this);
}
