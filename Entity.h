#include <unordered_set>
#include "Components/Component.h"
#include "ComponentManager.h"
#pragma once
class Entity
{
private:
    std::unordered_set<Components::Component*> components;
    /* data */
    int entityId;
public:
    Entity();
    ~Entity();
    int getComponentsBit();

    template<typename T, typename std::enable_if<std::is_base_of<Components::Component, T>::value>::type* = nullptr>
    T* GetCompoenet() {
        for each (Components::Component* com in components)
        {
            if (dynamic_cast<T*>(com) != nullptr)
                return dynamic_cast<T*>(com);
        }
    }

    template<typename T, typename std::enable_if<std::is_base_of<Components::Component, T>::value>::type* = nullptr>
    void AddComponent(T* component) {
        components.insert(component);
    }
    static void DestroyEntity(ComponentManager* componentManager, Entity* entity);
};
