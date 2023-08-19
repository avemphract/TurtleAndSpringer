#include <stack>

#include "ComponentManager.h"
#include "Components/Component.h"
#include "Components/TransformComponent.h"
#include "Components/VelocityComponent.h"

ComponentManager::ComponentManager():
    unusedTransformComponent { std::stack<Components::TransformComponent*>() },
    unusedVelocityComponent { std::stack<Components::VelocityComponent*>() }
{

}

ComponentManager::~ComponentManager()
{
}

template<>
inline void ComponentManager::ReturnComponent<Components::TransformComponent>(Components::TransformComponent* component) {
    unusedTransformComponent.push(component);
}
template<>
inline void ComponentManager::ReturnComponent<Components::VelocityComponent>(Components::VelocityComponent* component) {
    unusedVelocityComponent.push(component);
}
template<>
inline void ComponentManager::ReturnComponent<Components::ShapeComponent>(Components::ShapeComponent* component) {
    unusedShapeComponent.push(component);
}
template<>
inline void ComponentManager::ReturnComponent<Components::GardenComponent>(Components::GardenComponent* component) {
    unusedGardenComponent.push(component);
}
template<>
inline void ComponentManager::ReturnComponent<Components::TurtleComponent>(Components::TurtleComponent* component) {
    unusedTurtleComponent.push(component);
}
template<>
inline void ComponentManager::ReturnComponent<Components::SpringerComponent>(Components::SpringerComponent* component) {
    unusedSpringerComponent.push(component);
}


template<typename T, typename std::enable_if<std::is_base_of<Components::Component, T>::value>::type*>
T* ComponentManager::GetComponent(){
    throw std::exception("Not Implemented");
}



template<>
Components::TransformComponent* ComponentManager::GetComponent<Components::TransformComponent>(){
    if (this->unusedTransformComponent.empty()) {
        return new Components::TransformComponent();
    }
    else
    {
        auto t = unusedTransformComponent.top();
        unusedTransformComponent.pop();
        return t;
    }
}

template<>
Components::VelocityComponent* ComponentManager::GetComponent<Components::VelocityComponent>() {
    if (this->unusedVelocityComponent.empty()) {
        return new Components::VelocityComponent();
    }
    else
    {
        auto t = unusedVelocityComponent.top();
        unusedVelocityComponent.pop();
        return t;
    }
}
template<>
Components::ShapeComponent* ComponentManager::GetComponent<Components::ShapeComponent>() {
    if (this->unusedShapeComponent.empty()) {
        return new Components::ShapeComponent();
    }
    else
    {
        auto t = unusedShapeComponent.top();
        unusedShapeComponent.pop();
        return t;
    }
}

template<>
Components::GardenComponent* ComponentManager::GetComponent<Components::GardenComponent>() {
    if (this->unusedGardenComponent.empty()) {
        return new Components::GardenComponent();
    }
    else
    {
        auto t = unusedGardenComponent.top();
        unusedGardenComponent.pop();
        return t;
    }
}
template<>
Components::TurtleComponent* ComponentManager::GetComponent<Components::TurtleComponent>() {
    if (this->unusedShapeComponent.empty()) {
        return new Components::TurtleComponent();
    }
    else
    {
        auto t = unusedTurtleComponent.top();
        unusedTurtleComponent.pop();
        return t;
    }
}
template<>
Components::SpringerComponent* ComponentManager::GetComponent<Components::SpringerComponent>() {
    if (this->unusedSpringerComponent.empty()) {
        return new Components::SpringerComponent();
    }
    else
    {
        auto t = unusedSpringerComponent.top();
        unusedSpringerComponent.pop();
        return t;
    }
}