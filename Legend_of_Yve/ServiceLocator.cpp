#include "ServiceLocator.h"
#include "Service.h"

ServiceLocator* ServiceLocator::_instance = nullptr;

ServiceLocator* ServiceLocator::instance()
{
	if (_instance == nullptr)
	{
		_instance = new ServiceLocator();
	}

	return _instance;
}



ServiceLocator::ServiceLocator() = default;

ServiceLocator::~ServiceLocator()

{
	delete _instance;
}



