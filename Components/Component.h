#pragma once

namespace Components{
    class Component
    {
        private:
            /* data */
        public:
            bool operator=(Component& c2);
            virtual int getComponentId() = 0;
            virtual void resetComponent() = 0;
            Component(/* args */) = default;
            ~Component() = default;
    };
}
