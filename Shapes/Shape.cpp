#include "Shape.h"
#include "PointShape.h"
#include "ArcShape.h"
#include "RectangleShape.h"
#include <cmath>
#define M_PI           3.14159265358979323846  /* pi */


Shape::~Shape()
{
}

bool Shape::isOversectioned(Shape* shape1, Shape* shape)
{
	if (dynamic_cast<PointShape*>(shape1) != nullptr && dynamic_cast<RectangleShape*>(shape) != nullptr) {
		auto po = dynamic_cast<PointShape*>(shape1);
		auto rec = dynamic_cast<RectangleShape*>(shape);
		auto res =  (rec->x < po->x && po->x < rec->x + rec->width) && (rec->y < po->y && po->y < rec->y + rec->height);
		return res;
	}
	if(dynamic_cast<PointShape*>(shape1) !=nullptr && dynamic_cast<ArcShape*>(shape) != nullptr){
		auto po = dynamic_cast<PointShape*>(shape1);
		auto arc = dynamic_cast<ArcShape*>(shape);
		float a = std::atan2(po->x - arc->cenX, po->y - arc->cenY);
		float endAngle = (arc->startAngle + arc->lengthAngle);
		endAngle = endAngle >= 2 * M_PI ? endAngle - 2 * M_PI : endAngle;
		bool res;
		if (std::pow(po->x - arc->cenX, 2) + std::pow(po->x - arc->cenY, 2) < std::pow(arc->radius, 2)) {
			if (arc->startAngle < endAngle) {
				res = (arc->startAngle < a) && (a < endAngle);
			}
			else {
				res = arc->startAngle < a || a < endAngle;
			}
		}
		else {
			res = false;
		}
		return res;
	}
	return false;
}
