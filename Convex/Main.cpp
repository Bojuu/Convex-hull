#include <stdio.h>
#include <iostream>
#include <vector>
#include "Alg.h"
#include "Point.h"

void write(std::vector<Point>& vec) {
	std::cout << "Points of the convex hull (in order): " << std::endl;
	for (Point p : vec) {
		std::cout << p.x << " " << p.y << std::endl;
	}
}

int main() {			// ~ Graham scan algorithm

	double x;
	double y;
	std::cout << "Type the coordinates of the points. " << std::endl;
	std::cout << "Format: <x><space><y><enter> " << std::endl;
	std::cout << "Ready: EOF (ctrl+Z) " << std::endl;

	std::vector<Point> vec;
	std::vector<Point> hull;

	std::cin >> x >> y;
	while (!std::cin.eof()) {
		Point P(x, y);
		vec.push_back(P);
		std::cin >> x >> y;
	}

	Alg::make_hull(vec, hull);
	write(hull);

	getchar();
	return 0;
}