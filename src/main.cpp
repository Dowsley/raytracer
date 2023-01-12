#include <fstream>

#include "utils/arithmetics.cpp"

#include "structures/color.cpp"
#include "core/writer.cpp"

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
        }
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