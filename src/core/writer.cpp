#include "writer.h"
#include "../utils/arithmetics.h"

#include <cmath>

Writer::Writer(int imageWidth, int imageHeight)
{
    outputFile.open(OUTPUT_IMG_NAME);
    outputFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n" << MAX_COLOR_VALUE << "\n";
}

Writer::~Writer()
{
    outputFile.close();
}

void Writer::WriteRow(Color const &c, int samplesPerPixel)
{
    double r = c.r();
    double g = c.g();
    double b = c.b();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    double scale = 1.0 / samplesPerPixel;
    r  = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    int ir = std::round(Arithmetics::Scale(Arithmetics::Clamp(r, 0.0, 1.0), 0.0, 1.0, 0, MAX_COLOR_VALUE));
    int ig = std::round(Arithmetics::Scale(Arithmetics::Clamp(g, 0.0, 1.0), 0.0, 1.0, 0, MAX_COLOR_VALUE));
    int ib = std::round(Arithmetics::Scale(Arithmetics::Clamp(b, 0.0, 1.0), 0.0, 1.0, 0, MAX_COLOR_VALUE));

    outputFile << ir << ' ' << ig << ' ' << ib << '\n';
}
