#ifndef IMAGE_H
#define IMAGE_H

#include "../structures/color.h"

class Image
{
private:
    Color *buffer;
    int width;
    int height;

    int _transformCoords(int i, int j) const;

public:
    Image(int w, int h);
    ~Image();

    Color &GetPixel(int i, int j) const;
    void SetPixel(int i, int j, double r, double g, double b);
};

#endif
