#include "geometry.h"
#include "random.h"

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

Vec3 Geometry::GetRandomDirInHemisphere(const Vec3 &normal)
{
    Vec3 inUnitSphere = RandomPointInUnitSphere();
    if (inUnitSphere.Dot(normal) > 0.0) // In the same hemisphere as the normal
        return inUnitSphere;
    else
        return -inUnitSphere;
}

Vec3 Geometry::RandomPointInUnitDisk()
{
    while (true) {
        auto p = Vec3(Random::RandomDouble(-1,1), Random::RandomDouble(-1,1), 0);
        if (p.LengthSquared() >= 1) {
            continue;
        }
        return p;
    }
}