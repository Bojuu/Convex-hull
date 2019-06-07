#ifndef POINT_H
#define POINT_H

struct Point {
	double x;
	double y;

	Point(double x = 0.0, double y = 0.0);
	bool same(Point& P);
	int left_right(Point& M, Point& E);
	double angle_cos(Point& P);
	double length(Point& P);
};

#endif
