#include "writer.h"

Writer::Writer(int imageWidth, int imageHeight)
{
    outputFile.open(OUTPUT_IMG_NAME);
    outputFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n" << MAX_COLOR_VALUE << "\n";
}

Writer::~Writer()
{
    outputFile.close();
}

void Writer::WriteRow(Color const &c)
{
    int ir = Arithmetics::scale(c.r, 0.0f, 1.0f, 0, MAX_COLOR_VALUE);
    int ig = Arithmetics::scale(c.g, 0.0f, 1.0f, 0, MAX_COLOR_VALUE);
    int ib = Arithmetics::scale(c.b, 0.0f, 1.0f, 0, MAX_COLOR_VALUE);

    outputFile << ir << ' ' << ig << ' ' << ib << '\n';
}
