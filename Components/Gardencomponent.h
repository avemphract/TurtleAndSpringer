#include "Component.h"
#pragma once

#define GardenComponentId 0b100000
namespace Components{
    class GardenComponent:public Component
    {
    private:
        /* data */
    public:
        int getComponentId() { return GardenComponentId; }
        void resetComponent() {};
        GardenComponent() = default;
    };
}