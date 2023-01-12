#include "color.h"

#include <stdexcept>

Color::Color(float r, float g, float b)
{
    SetRed(r);
    SetGreen(g);
    SetBlue(b);
}

float Color::ValidateColorValue(float val)
{
    if (!(val >= 0.0f && val <= 1.0f)) {
        throw std::invalid_argument("Color value must be between 0.0f and 1.0f range.");
    }
    return val;
}

void Color::SetRed(float val)
{
    this->r = ValidateColorValue(val);
}
void Color::SetGreen(float val)
{
    this->g = ValidateColorValue(val);
}
void Color::SetBlue(float val)
{
    this->b = ValidateColorValue(val);
}
