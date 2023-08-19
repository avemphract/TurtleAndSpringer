#include "../Entity.h"
#pragma once
class System{
private:
	int requiredComponents;
public:
	int priorty = 0;
	System(int requiredComponents);
	virtual void update(std::list<Entity*> &entity, float deltaTime);
	virtual void update(Entity* entity, float deltaTime) = 0;
	bool operator<(const System& rhs);
protected:
	virtual void beforeUpdate(std::list<Entity*> &entity){ };
};