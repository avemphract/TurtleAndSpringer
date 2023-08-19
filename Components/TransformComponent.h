#include "Component.h"
#include <type_traits>
#pragma once
#define TransformComponentId 0b1
namespace Components{
    class TransformComponent: public Component
    {
        public:
            float posX;
            float posY;
            float angle;
            TransformComponent* setComponent(float posX, float posY, float angle);
            int getComponentId();
            void resetComponent();
            TransformComponent();
    };
}
