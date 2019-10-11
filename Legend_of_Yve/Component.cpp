#include "Component.h"
#include "ServiceLocator.h"
#include "GameLoop.h"
void Component::Register()
{
	ServiceLocator::instance()->GetService<GameLoop>()->Register(this);
}
