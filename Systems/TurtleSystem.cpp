#include "TurtleSystem.h"
#include "../Components/TurtleComponent.h"
#include "../Components/GardenComponent.h"
#include "../Components/SpringerComponent.h"
#include "../Components/ShapeComponent.h"
#include "../Components/VelocityComponent.h"
#include "../Shapes/PointShape.h"
#include <iostream>
#include "../Shapes/RectangleShape.h"

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
    auto enVelocity = entity->GetComponent<VelocityComponent>();
    auto enShape = entity->GetComponent<ShapeComponent>();

    auto garTransform = garden->GetComponent<TransformComponent>();
    auto garShape = garden->GetComponent<ShapeComponent>();

    if (!Shape::isOversectioned(enShape->shape->modifyTransform(enTransform), garShape->shape->modifyTransform(garTransform))){
        std::cout << "Kaplumbağa bahçenin dışına çıktı" << std::endl;

        game->isRunning = false;
        RectangleShape* gardenRect = dynamic_cast<RectangleShape*>((garShape->shape));
        PointShape p1;
        PointShape p2;
        if (enVelocity->velX > 0) {
            p1 = getExitPoint(
                PointShape(enTransform->posX, enTransform->posY), PointShape(enTransform->posX + enVelocity->velX, enTransform->posY + enVelocity->velY),
                PointShape(gardenRect->x + gardenRect->width, gardenRect->y), PointShape(gardenRect->x + gardenRect->width, gardenRect->y + gardenRect->height));
        }
        else
        {
            p1 = getExitPoint(
                PointShape(enTransform->posX, enTransform->posY), PointShape(enTransform->posX + enVelocity->velX, enTransform->posY + enVelocity->velY),
                PointShape(gardenRect->x, gardenRect->y), PointShape(gardenRect->x, gardenRect->y + gardenRect->height));
        }
        if (enVelocity->velY > 0) {
            p2 = getExitPoint(
                PointShape(enTransform->posX, enTransform->posY), PointShape(enTransform->posX + enVelocity->velX, enTransform->posY + enVelocity->velY),
                PointShape(gardenRect->x, gardenRect->y + gardenRect->height), PointShape(gardenRect->x + gardenRect->width, gardenRect->y + gardenRect->height));
        }
        else
        {
            p2 = getExitPoint(
                PointShape(enTransform->posX, enTransform->posY), PointShape(enTransform->posX + enVelocity->velX, enTransform->posY + enVelocity->velY),
                PointShape(gardenRect->x, gardenRect->y), PointShape(gardenRect->x + gardenRect->width, gardenRect->y));
        }
        if (Shape::isOversectioned(&p1, new RectangleShape(gardenRect))) {
            std::cout << "Bahçenin (" << p1.x << "," << p1.y << ") noktasından dışarı çıktı";
        }
        else
        {
            std::cout << "Bahçenin (" << p2.x << "," << p2.y << ") noktasından dışarı çıktı";
        }
    }
    else
    {
        std::cout << "Kaplumbağa bahçenin içinde" << std::endl;

    }

    for (Entity* springer: springers) {
        auto sprTransform = springer->GetComponent<TransformComponent>();
        auto sprShape = springer->GetComponent<ShapeComponent>();
        if (Shape::isOversectioned(enShape->shape->modifyTransform(enTransform), sprShape->shape->modifyTransform(sprTransform))){
            std::cout << "Kaplumbağa ıslandı." << std::endl;
        }
    }
}

PointShape TurtleSystem::getExitPoint(PointShape turtle_p1, PointShape turtle_p2, PointShape boundary_p1, PointShape boundary_p2)
{
    PointShape intersection = PointShape(0.0, 0.0);

    double x1 = turtle_p1.x, y1 = turtle_p1.y;
    double x2 = turtle_p2.x, y2 = turtle_p2.y;
    double x3 = boundary_p1.x, y3 = boundary_p1.y;
    double x4 = boundary_p2.x, y4 = boundary_p2.y;


    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (denominator == 0) {
        std::cerr << "Lines are parallel or coincident. No intersection." << std::endl;
        return intersection;
    }


    double px = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denominator;
    double py = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denominator;

    intersection.x = px;
    intersection.y = py;

    return intersection;
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
