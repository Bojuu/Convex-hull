#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Point.h"

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

double Point::get_x() { return x; }
double Point::get_y() { return y; }

bool Point::same(Point& P) {
	return (x == P.x && y == P.y);
}

int Point::left_right(Point& M, Point& E) {		// this->M->E vectors turn direction

	double vex = (M.x - x)*(E.y - y) - (E.x - x)*(M.y - y);	    // cross product
	if (vex < 0) return -1;  // right turn
	if (vex > 0) return 1;	 // left turn
	return 0;				 // in a straight
}

double Point::angle_cos(Point& P) {	// cosinus calculation
									// othogonal projection of P -> right triangle
	if (same(P)) {
		return 0.0;
	}
	else {
		double l = length(P);
		return (P.x - x) / l;
	}
}

double Point::length(Point& P) {		// distance between the points
	return sqrt(pow(x - P.x, 2) + pow(y - P.y, 2));
}

void Point::write() {
	std::cout << x << " " << y << std::endl;
}