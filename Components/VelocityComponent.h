#include "Component.h"
#include <type_traits>
#pragma once

#define VelocityComponentId 0b10
namespace Components{
    class VelocityComponent: public Component
    {
    public:
        float velX;
        float velY;
        float velA;
        VelocityComponent* setComponent(float velX, float velY, float velA);
        int getComponentId();
        void resetComponent();
        VelocityComponent();

    };
}