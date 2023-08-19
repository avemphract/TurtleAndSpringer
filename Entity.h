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
    T* GetComponent() {
        for(Components::Component* com : components)
        {
            if (dynamic_cast<T*>(com) != nullptr)
                return dynamic_cast<T*>(com);
        }
        return nullptr;
    }

    template<typename T, typename std::enable_if<std::is_base_of<Components::Component, T>::value>::type* = nullptr>
    void AddComponent(T* component) {
        components.insert(component);
    }
    static void DestroyEntity(ComponentManager* componentManager, Entity* entity);
};

enum EntityStatus {
    PASSIVE, ACTIVE, DELETED
};