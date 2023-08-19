#include <type_traits>
#include "../Components/TransformComponent.h"
#pragma once
class Shape{

    public:
        Shape() = default;
        ~Shape();
        virtual Shape* modifyTransform(Components::TransformComponent* transformComponent) = 0;

        static bool isOversectioned(Shape* shape1, Shape* shape);
};


