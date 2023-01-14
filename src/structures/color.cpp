#include "color.h"

#include <stdexcept>

Color::Color(double r, double g, double b)
{
    SetRed(r);
    SetGreen(g);
    SetBlue(b);
}

Color::Color(Vec3 v)
{
    SetRed(v[0]);
    SetGreen(v[1]);
    SetBlue(v[2]);
}

double Color::ValidateColorValue(double val)
{
    if (!(val >= 0.0f && val <= 1.0f)) {
        throw std::invalid_argument("Color value must be between 0.0f and 1.0f range.");
    }
    return val;
}

void Color::SetRed(double val)
{
    this->e[0] = ValidateColorValue(val);
}
void Color::SetGreen(double val)
{
    this->e[1] = ValidateColorValue(val);
}
void Color::SetBlue(double val)
{
    this->e[2] = ValidateColorValue(val);
}

double Color::r() const { return this->e[0]; }
double Color::g() const { return this->e[1]; }
double Color::b() const { return this->e[2]; }
