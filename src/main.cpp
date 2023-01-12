#define PROGRESS_NUM_BARS 30

#include <iostream>

#include "utils/index.h"
#include "structures/index.h"
#include "core/index.h"

class RayTracer
{
public:
	RayTracer(int imageWidth, int imageHeight) {
        this->imageWidth = imageWidth;
        this->imageHeight = imageHeight;
        writer = new Writer(imageWidth, imageHeight);
    }

    ~RayTracer() {
        delete writer;
    }

    void Render() const
    {
        for (int j = 0; j < imageHeight; j++)
        {
            for (int i = 0; i < imageWidth; i++)
            {
                // Percentage of progress: Quick way to get a num between 0 and 1
                Color c = Color(
                    0.25,
                    (double) i / (imageWidth),
                    (double) j / (imageHeight)
                );
                writer->WriteRow(c);
            }
            LogProgress((double) (j+1) / imageHeight);
        }
    }

    void LogProgress(float perc) const
    {
        if (!(perc >= 0.0f && perc <= 1.0f)) {
            throw std::invalid_argument("Progress percentage value must be between 0.0f and 1.0f range.");
        }

        int progress_scaled = Arithmetics::scale(perc, 0.0f, 1.0f, 0.0f, PROGRESS_NUM_BARS);

        std::cout << "[";
        for (int i = 0; i < PROGRESS_NUM_BARS; i++) {
            if (progress_scaled >= i) {
                std::cout << "=";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "]" << " (" << perc * 100 << "%)\n";
    }

private:
    int imageWidth;
    int imageHeight;
    Writer *writer;
};


int main(int argc, char const *argv[])
{
	RayTracer rayTracer = RayTracer(256, 256);

	rayTracer.Render();

    return 0;
}
