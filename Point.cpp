#include "Point.h"

Point Point::operator+(const Point& v) {
	Point tmp;
	tmp.x = x + v.x;
	tmp.y = y + v.y;
	return tmp;
}
