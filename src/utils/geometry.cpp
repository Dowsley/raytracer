#include "geometry.h"

#include <limits>

const double Geometry::infinity = std::numeric_limits<double>::infinity();

double Geometry::DegreesToRadians(double degrees)
{
    return degrees * pi / 180.0;
}

// TODO: Change this to something more efficient
Vec3 Geometry::RandomPointInUnitSphere()
{
    while (true) {
        Vec3 p = Vec3::Random(-1, 1);
        if (p.LengthSquared() >= 1) {
            continue;
        } 
        return p;
    }
}