#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <type_traits>
#include <string>

class Service;


class ServiceLocator
{

private:
	ServiceLocator();

	~ServiceLocator();

	static ServiceLocator* _instance;
	std::vector<Service*> _services;



public:
	static ServiceLocator* instance();
	template<typename T>
	void AddService(T& t_service);
	template<typename T>
	T* GetService();
	template<typename T>
	T* FindService();


};

template<typename T>
void ServiceLocator::AddService(T& t_service)
{
	_services.push_back(dynamic_cast<Service*>(&t_service));
}




template<typename T>
T* ServiceLocator::GetService()
{
	T* service = FindService<T>();
	return service;

}

template<typename T>
T* ServiceLocator::FindService()
{

	for (int i = 0; i < _services.size(); ++i)
	{
		T* cast_service = dynamic_cast<T*>(_services[i]);
		if (cast_service != nullptr)
		{
			return cast_service;
		}
	}
}










