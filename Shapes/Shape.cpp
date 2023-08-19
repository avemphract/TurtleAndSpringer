#include "Shape.h"
#include "PointShape.h"
#include "ArcShape.h"

template<typename T, typename K, typename std::enable_if<std::is_base_of<Shape, T>::value>::type*, typename std::enable_if<std::is_base_of<Shape, K>::value>::type*>
inline bool Shape::isOversectioned(T shape1, K shape)
{
    throw std::exception("NotImplemented");
}
template<>
inline bool Shape::isOversectioned<PointShape, ArcShape>(PointShape shape1, ArcShape shap) {

}

Shape::~Shape()
{
}
