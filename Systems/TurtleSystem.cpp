#include "TurtleSystem.h"
#include "../Components/TurtleComponent.h"
#include "../Components/GardenComponent.h"
#include "../Components/SpringerComponent.h"
#include "../Components/ShapeComponent.h"
#include <iostream>

using namespace Components;

TurtleSystem::TurtleSystem(Game* game):System(TurtleComponentId),game{game}
{
}

TurtleSystem::~TurtleSystem()
{
}

void TurtleSystem::update(Entity* entity, float deltaTime)
{
    auto enTransform = entity->GetComponent<TransformComponent>();
    auto enShape = entity->GetComponent<ShapeComponent>();

    auto garTransform = garden->GetComponent<TransformComponent>();
    auto garShape = garden->GetComponent<ShapeComponent>();
    if (!Shape::isOversectioned(enShape->shape->modifyTransform(enTransform), garShape->shape->modifyTransform(garTransform))){
        std::cout << "Kaplumbağa bahçenin dışına çıktı" << std::endl;
        game->isRunning = false;
    }
    else
    {
        std::cout << "Kaplumbağa dışarda" << std::endl;
    }

    for (Entity* springer: springers) {
        auto sprTransform = springer->GetComponent<TransformComponent>();
        auto sprShape = springer->GetComponent<ShapeComponent>();
        if (Shape::isOversectioned(enShape->shape->modifyTransform(enTransform), sprShape->shape->modifyTransform(sprTransform))){
            std::cout << "Kaplumbağa ıslandı." << std::endl;
        }
    }
}

void TurtleSystem::beforeUpdate(std::list<Entity*> &entityList)
{
    for(Entity* entity: entityList){
        if (entity->GetComponent<GardenComponent>() != nullptr) {
            garden = entity;
        }
    }

    springers.clear();
    for (Entity* entity : entityList) {
        if (entity->GetComponent<SpringerComponent>() != nullptr) {
            springers.push_front(entity);
        }
    }
}
