#include "Game.h"
#include "Systems/VelocitySystem.h"
#pragma once
int main(){
    Game game;
    game.registerSytem(new VelocitySystem());
    Entity* turtle = game.getAndRegisterEntity();
    turtle->AddComponent(game.componentManager.GetComponent<Components::TransformComponent>());
    turtle->AddComponent(game.componentManager.GetComponent<Components::VelocityComponent>());
    float fixedDeltaTime = 0.1;
    while (true) {
        game.update(fixedDeltaTime);
    }
}