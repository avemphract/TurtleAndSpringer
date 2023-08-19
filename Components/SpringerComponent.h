#include "Component.h"

#define SpringerComponentId 0b1000000
#pragma once
namespace Components{
    class SpringerComponent:public Component
    {
    private:
        /* data */
    public:
        int getComponentId() { return SpringerComponentId; }
        void resetComponent() {};
        SpringerComponent() = default;
    };
    
}