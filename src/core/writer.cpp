#include "writer.h"
#include "../utils/arithmetics.h"

#include <cmath>

void Writer::Open(int imageWidth, int imageHeight)
{
    outputFile.open(OUTPUT_IMG_NAME);
    outputFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n" << MAX_COLOR_VALUE << "\n";
}

void Writer::Close()
{
    outputFile.close();
}

void Writer::WriteRow(Color const &c, int samplesPerPixel)
{
    int ir = std::round(Arithmetics::Scale(c.r(), 0.0, 1.0, 0, MAX_COLOR_VALUE));
    int ig = std::round(Arithmetics::Scale(c.g(), 0.0, 1.0, 0, MAX_COLOR_VALUE));
    int ib = std::round(Arithmetics::Scale(c.b(), 0.0, 1.0, 0, MAX_COLOR_VALUE));

    outputFile << ir << ' ' << ig << ' ' << ib << '\n';
}
