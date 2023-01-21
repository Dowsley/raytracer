#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "../structures/vec3.h"

class Geometry
{
    public:
        static const double infinity; 
        constexpr static const double pi = 3.1415926535897932385;

        static double DegreesToRadians(double degrees);
        static Vec3 RandomPointInUnitSphere();
        static Vec3 GetRandomDirInHemisphere(const Vec3 &normal);
        static Vec3 RandomPointInUnitDisk();
};

#endif