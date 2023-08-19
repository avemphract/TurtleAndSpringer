#include "Game.h"
#include "Entity.h"

void Game::update(float deltaTime)
{
	auto temp = registeredSystems;
	while (!temp.empty())
	{
		temp.top()->update(this->entities, deltaTime);
        temp.pop();
	}
}

Entity* Game::getAndRegisterEntity()
{
    Entity* entity = nullptr;
    if (this->unusedEntities.empty()) {
        entity = new Entity();
    }
    else
    {
        entity = unusedEntities.top();
        unusedEntities.pop();
    }
    entities.push_front(entity);
    return entity;
}
