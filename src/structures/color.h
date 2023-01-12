#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

class Color : public Vec3
{
    public:
        Color(double r, double g, double b);
	    // ~Color();

        double ValidateColorValue(double val);
        void SetRed(double val);
        void SetGreen(double val);
        void SetBlue(double val);
        double r() const;
        double g() const;
        double b() const;
};

#endif
