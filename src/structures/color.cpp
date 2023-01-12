#include "color.h"

#include <stdexcept>

Color::Color(float r, float g, float b) {
    setRed(r);
    setGreen(g);
    setBlue(b);
}

float Color::validateColorValue(float val) {
    if (!(val >= 0.0f && val <= 1.0f)) {
        throw std::invalid_argument("Color value must be between 0.0f and 1.0f range.");
    }
    return val;
}

void Color::setRed(float val) {
    this->r = validateColorValue(val);
}
void Color::setGreen(float val) {
    this->g = validateColorValue(val);
}
void Color::setBlue(float val) {
    this->b = validateColorValue(val);
}
