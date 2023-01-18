#ifndef WRITER_H
#define WRITER_H

#include <fstream>

#include "../structures/color.h"

class Writer
{
    public:
        void WriteRow(Color const &c, int samplesPerPixel);
        void Open(int imageWidth, int imageHeight);
        void Close();

    private:
        std::ofstream outputFile;
        std::string OUTPUT_IMG_NAME = "output.ppm";
        int MAX_COLOR_VALUE = 255;
};

#endif