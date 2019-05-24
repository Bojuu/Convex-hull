#ifndef ALG_H
#define ALG_H

#include <vector>
#include "Point.h"

namespace Alg {
	void make_hull(const std::vector<Point>& data, std::vector<Point>& hull);
};

#endif