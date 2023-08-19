#include <queue>
#include <list>
#include <stack>
#include "Systems/System.h"

#pragma once
class Game
{
private:
	std::priority_queue<System*> registeredSystems = std::priority_queue<System*>();
	std::list<Entity*> entities = std::list<Entity*>();
	std::stack<Entity*> unusedEntities = std::stack<Entity*>();
public:
	ComponentManager componentManager;
	bool isRunning = true;

	void update(float deltaTime);
	Entity* getAndRegisterEntity();

	template<typename T, typename std::enable_if<std::is_base_of<System, T>::value>::type* = nullptr>
	void registerSytem(T* system) {
		registeredSystems.push(system);
	}
};