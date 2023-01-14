#include "geometry.h"

#include <limits>

const double Geometry::infinity = std::numeric_limits<double>::infinity();

double Geometry::DegreesToRadians(double degrees)
{
    return degrees * pi / 180.0;
}