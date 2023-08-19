#include "Entity.h"

Entity::Entity(/* args */)
{
    static int nextEntityId = 1;
    entityId = nextEntityId++;
}

Entity::~Entity()
{
}

int Entity::getComponentsBit()
{
    auto res = 0;
    for(Components::Component * com : this->components)
    {
        res |= com->getComponentId();
    }
    return res;
}

void Entity::DestroyEntity(ComponentManager* componentManager, Entity* entity)
{
    for(Components::Component* com : entity->components)
    {
        componentManager->ReturnComponent(com);
    }
    (*entity).components.clear();
}
