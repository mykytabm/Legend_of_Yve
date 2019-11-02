#include "RenderComponent.h"
#include "RenderManager.h"
#include "GameLoop.h"
void RenderComponent::Register(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	t_renderManager.Register(this);
	Component::Register(t_gameLoop, t_renderManager);
}
void RenderComponent::DeRegister(GameLoop& t_gameLoop, RenderManager& t_renderManager)
{
	t_renderManager.DeRegister(this);
	Component::DeRegister(t_gameLoop, t_renderManager);
}

