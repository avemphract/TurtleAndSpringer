#include <type_traits>
#include "../Components/TransformComponent.h"
#pragma once
class Shape{

    public:
        Shape() = default;
        ~Shape();
        template<typename T,typename K, typename std::enable_if<std::is_base_of<Shape, T>::value>::type* = nullptr, typename std::enable_if<std::is_base_of<Shape, K>::value>::type* = nullptr>
        static bool isOversectioned(T shape1, K shape);
};


