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

template<typename T, typename std::enable_if<std::is_base_of<Components::Component, T>::value>::type* = nullptr>
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

