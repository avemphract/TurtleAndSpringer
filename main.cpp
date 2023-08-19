#include <iostream>
#include "Game.h"
#include "Systems/VelocitySystem.h"
#include "Systems/TurtleSystem.h"
#include "Components/TurtleComponent.h"
#include "Components/GardenComponent.h"
#include "Shapes/PointShape.h"
#include "Shapes/RectangleShape.h"
#include "Shapes/ArcShape.h"
#define M_PI           3.14159265358979323846  /* pi */

#pragma once
int main(){
    Game game;
    game.registerSytem(new VelocitySystem());
    game.registerSytem(new TurtleSystem(&game));
    
    Entity* turtle = game.getAndRegisterEntity();
    turtle->AddComponent(game.componentManager.GetComponent<Components::TransformComponent>()->setComponent(0, 0, 0));
    turtle->AddComponent(game.componentManager.GetComponent<Components::VelocityComponent>()->setComponent(10, 20, 0));
    turtle->AddComponent(game.componentManager.GetComponent<Components::ShapeComponent>()->setComponent(new PointShape()));
    turtle->AddComponent(game.componentManager.GetComponent<Components::TurtleComponent>());

    Entity* garden = game.getAndRegisterEntity();
    garden->AddComponent(game.componentManager.GetComponent<Components::TransformComponent>()->setComponent(0,0,0));
    garden->AddComponent(game.componentManager.GetComponent<Components::ShapeComponent>()->setComponent(new RectangleShape(0, 0, 50, 50)));
    garden->AddComponent(game.componentManager.GetComponent<Components::GardenComponent>());

    Entity* springler = game.getAndRegisterEntity();
    springler->AddComponent(game.componentManager.GetComponent<Components::TransformComponent>()->setComponent(0,0,0));
    springler->AddComponent(game.componentManager.GetComponent<Components::ShapeComponent>()->setComponent(new ArcShape(0, 0, 0, M_PI/2, 10)));
    springler->AddComponent(game.componentManager.GetComponent<Components::SpringerComponent>());


    float fixedDeltaTime = 1;
    while (game.isRunning) {
        game.update(fixedDeltaTime);
    }
    std::cout << "Kapbumbaya bahçenin dışına çıktığı için oyun bitti" << std::endl;
}