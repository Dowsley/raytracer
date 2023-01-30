#include "image.h"

Image::Image(int w, int h)
: width(w), height(h) {
    buffer = new Color[w*h];
}

Image::~Image() {
    delete[] buffer;
}

int Image::_transformCoords(int i, int j) const
{
    return j * width + i;
}

Color &Image::GetPixel(int i, int j) const
{
    return buffer[_transformCoords(i,j)];
}

void Image::SetPixel(int i, int j, double r, double g, double b)
{
    buffer[_transformCoords(i,j)] = Color(Vec3(r,g,b));
}
