#pragma once
#include <vector>

template <typename T>
class IRepository
{
public:

	virtual ~IRepository() {}
	virtual std::vector<T*> getAll() = 0;
	virtual int add(T* entity) = 0;
	virtual void update(T* entity) = 0;
	virtual void remove(int id) = 0;
};