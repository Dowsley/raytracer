#ifndef WRITER_H
#define WRITER_H

#include <fstream>

#include "../structures/color.h"

class Writer
{
    public:
        Writer(int imageWidth, int imageHeight);
	    ~Writer();
        void WriteRow(Color const &c, int samplesPerPixel);

    private:
        std::ofstream outputFile;
        std::string OUTPUT_IMG_NAME = "output.ppm";
        int MAX_COLOR_VALUE = 255;
};

#endif