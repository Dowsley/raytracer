#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry
{
    public:
        static const double infinity; 
        constexpr static const double pi = 3.1415926535897932385;

        static double DegreesToRadians(double degrees);
};

#endif