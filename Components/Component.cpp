#include "Component.h"
#include <typeinfo>

bool Components::Component::operator=(Components::Component& c2){
    return typeid(this) == typeid(c2);
}