#include "Component.h"
#include "../Shapes/Shape.h"
#define ShapeComponentId 0b100
#pragma once
namespace Components{
    class ShapeComponent: public Component{
        public:
        Shape* shape;
        ShapeComponent* setComponent(Shape* shape);
        int getComponentId();
        void resetComponent();
        ShapeComponent();
        ~ShapeComponent();
    };
}