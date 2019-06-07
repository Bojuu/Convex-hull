#include <stdio.h>
#include <iostream>
#include <algorithm>

#include "Alg.h"
#include "Point.h"

using namespace Alg;

namespace {

	Point base;

	bool compare_points(Point& p1, Point& p2) {
		if (base.angle_cos(p1) == base.angle_cos(p2)) {
			return base.length(p1) < base.length(p2);
		}
		else {
			return base.angle_cos(p1) > base.angle_cos(p2);
		}
	}

	void base_choose(std::vector<Point>& data) {	// choosing the base point (the one with the lowest y coord)

		double min_y = data[0].y;
		int index = 0;

		for (unsigned int i = 1; i < data.size(); i++) {
			double temp_y = data[i].y;
			if (temp_y < min_y) {
				min_y = temp_y;
				index = i;
			}
			else if (temp_y == min_y) {		// equal y -> lower x
				if (data[i].x < data[index].y) {
					index = i;
				}
			}
		}

		if (index != 0) {	// the base will be the first (swap)
			Point temp_point = data[0];
			data[0] = data[index];
			data[index] = temp_point;
		}

		base = data[0];
	}
}

void Alg::make_hull(const std::vector<Point>& data, std::vector<Point>& hull) {
	
	for (Point p : data) {
		hull.push_back(p);			// at first every point is in the hull
	}

	if (hull.size() <= 2) {			// if there are less than 3 points
		if (hull.size() == 2 && hull[0].same(hull[1])) {
			hull.pop_back();
		}
		return;
	}

	base_choose(hull);

	std::vector<Point>::iterator it;	// if there are more base points -> erase
	for (it = hull.begin()+1; it != hull.end(); ) {
		if (hull[0].same(*it)) {
			it = hull.erase(it);
		}
		else {
			it++;
		}
	}

	std::sort(hull.begin() + 1, hull.end(), compare_points);

	int i = 0;
	bool end = false;

	while (!end) {		// i -> i+1 -> i+2 examinations (left or right)

		double dir = hull[i].left_right(hull[i + 1], hull[i + 2]);

		if (dir == 1 || dir == 0) {			// if it's a left turn (or straight), the points remain
			i++;
			if (i + 2 == hull.size()) {		// if that's the last point: true end
				end = true;
			}
		}
		else if (dir == -1) {						// if it's a right turn...
			hull.erase(hull.begin() + i + 1);		// the middle point (i+1) is surely not hull-member
			i--;									// examination with one step back
		}
	}
}

