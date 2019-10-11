#include "ServiceLocator.h"
#include "Service.h"

ServiceLocator* ServiceLocator::m_instance = nullptr;

ServiceLocator* ServiceLocator::instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ServiceLocator();
	}

	return m_instance;
}



ServiceLocator::ServiceLocator() = default;

ServiceLocator::~ServiceLocator()
{
	m_services.clear();
}



