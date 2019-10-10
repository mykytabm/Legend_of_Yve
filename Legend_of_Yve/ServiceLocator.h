#pragma once
#include <set>
class Service;

class ServiceLocator
{

private:
	ServiceLocator();
	~ServiceLocator();
	static ServiceLocator* m_instance;
	std::set<Service*> m_services;

public:
	static ServiceLocator* instance();

	template<typename T>
	void AddService(T* t_service);

	template<typename T>
	void RemoveService(T* t_service);

	template<typename T>
	T* GetService();

	template<typename T>
	T* FindService();


};

