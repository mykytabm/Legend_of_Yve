#include "RenderComponent.h"
#include "RenderManager.h"
#include "GameLoop.h"
void RenderComponent::Register(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	t_renderManager.Register(this);
	Component::Register(t_gameLoop, t_renderManager);
}
