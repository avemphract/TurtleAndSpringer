#include <stack>
#include "Components/TransformComponent.h"
#include "Components/VelocityComponent.h"
#include "Components/Component.h"
#include <type_traits>
#include "Components/ShapeComponent.h"
#include "Components/GardenComponent.h"
#include "Components/TurtleComponent.h"
#include "Components/SpringerComponent.h"

class ComponentManager
{
private:
    std::stack<Components::TransformComponent*> unusedTransformComponent;
    std::stack<Components::VelocityComponent*> unusedVelocityComponent;
    std::stack<Components::ShapeComponent*> unusedShapeComponent;
    std::stack<Components::GardenComponent*> unusedGardenComponent;
    std::stack<Components::TurtleComponent*> unusedTurtleComponent;
    std::stack<Components::SpringerComponent*> unusedSpringerComponent;
    /* data */
public:
    ComponentManager(/* args */);
    ~ComponentManager();
    
    template<typename T, typename std::enable_if<std::is_base_of<Components::Component, T>::value>::type* = nullptr>
    T* GetComponent();


    template<typename T, typename std::enable_if<std::is_base_of<Components::Component,T>::value>::type* = nullptr>
    void ReturnComponent(T* component) {};
};