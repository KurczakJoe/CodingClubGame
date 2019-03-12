#ifndef POINT_H
#define POINT_H
#pragma once

struct Point {
	int x;
	int y;
	Point operator+(const Point& v);
};

#endif
