#define OLC_PGE_APPLICATION

#define MAX_DEPTH 50
#define PROGRESS_NUM_BARS 30

#include <iostream>
#include <cmath>

#include "graphics/olcPixelGameEngine.h"
#include "utils/index.h"
#include "structures/index.h"
#include "core/index.h"

class RayTracer : public olc::PixelGameEngine
{
public:
    /* Image */
    constexpr static const double aspectRatio = 3.0 / 2.0;
    constexpr static const int imageWidth = 1200;
    constexpr static const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

	RayTracer() {
		sAppName = "RayTracer";
	}

private:
    World world = World::GenerateRandom();
    Writer writer;

    /* Camera */
    Vec3 lookFrom = Vec3(13, -2, 3);
    Vec3 lookAt = Vec3(0.0, 0.0, 0.0);
    Vec3 viewUpDir = Vec3(0.0, 1.0, 0.0);
    double distToFocus = 10.0;
    double aperture = 0.1;
    Camera cam = Camera(
        lookFrom,
        lookAt,
        viewUpDir,
        30,
        aspectRatio,
        aperture,
        distToFocus
    );

    /* Others */
    const int maxRayRecursionDepth = 50;
    const int samplesPerPixel = 10;

protected:
	bool OnUserCreate() override
	{
        Render(true);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if (GetKey(olc::Key::R).bReleased) {
            Render(true);
		}
        return true;
	}

    void DrawColor(const olc::vi2d pos, Color &c, int samplesPerPixel)
    {
        double r = c.r();
        double g = c.g();
        double b = c.b();

        // Divide the color by the number of samples and gamma-correct for gamma=2.0.
        double scale = 1.0 / samplesPerPixel;
        r = sqrt(scale * r);
        g = sqrt(scale * g);
        b = sqrt(scale * b);

        int ir = std::round(Arithmetics::Scale(Arithmetics::Clamp(r, 0.0, 1.0), 0.0, 1.0, 0, 255));
        int ig = std::round(Arithmetics::Scale(Arithmetics::Clamp(g, 0.0, 1.0), 0.0, 1.0, 0, 255));
        int ib = std::round(Arithmetics::Scale(Arithmetics::Clamp(b, 0.0, 1.0), 0.0, 1.0, 0, 255));

        Draw(
            pos,
            olc::Pixel(ir, ig, ib)
        );
    }

    void Render(bool outputToImage=false)
    {
        if (outputToImage)
            writer.Open(imageWidth, imageHeight);
            
        for (int j = 0; j < imageHeight; j++)
        {
            for (int i = 0; i < imageWidth; i++)
            {
                Color pixelColor(0, 0, 0);
                for (int s = 0; s < samplesPerPixel; ++s) {
                    // This gets a percentage so we can traverse the viewport.
                    auto u = (i + Random::RandomDouble()) / (imageWidth-1);
                    auto v = (j + Random::RandomDouble()) / (imageHeight-1);

                    Ray r = cam.GetRay(u, v);
                    pixelColor += GetRayColor(r, maxRayRecursionDepth);
                }
                if (outputToImage) {
                    writer.WriteRow(pixelColor, samplesPerPixel);
                }
                DrawColor(olc::vi2d(i, j), pixelColor, samplesPerPixel);
            }
            LogProgress((double) (j+1) / imageHeight);
        }
        if (outputToImage)
            writer.Close();
    }

    Color GetRayColor(const Ray &r, int depth) const
    {
        if (depth <= 0)
            return Color(0, 0, 0);

        HitRecord rec;
        // 0.001 instead of 0 so we can offset for float approximation.
        // Solves the shadow acne problem (yup)
        if (world.CheckHit(r, 0.001, Geometry::infinity, rec)) {
            Ray scattered;
            Color attenuation;
            if (rec.material->Scatter(r, rec, attenuation, scattered)) {
                return attenuation * GetRayColor(scattered, depth-1);
            }
            return Color(0,0,0);
        }

        Vec3 unitDirection = r.GetDirection().UnitVector();
        auto t = 0.5 * (unitDirection.y() + 1.0);
        return Color((1.0 - t) * Color(0.5, 0.7, 1.0) + t * Color(1.0, 1.0, 1.0)); // lerp
    }

    void LogProgress(float perc) const
    {
        if (!(perc >= 0.0f && perc <= 1.0f)) {
            throw std::invalid_argument("Progress percentage value must be between 0.0f and 1.0f range.");
        }

        int progress_scaled = Arithmetics::Scale(perc, 0.0, 1.0, 0.0, PROGRESS_NUM_BARS);

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
};


int main(int argc, char const *argv[])
{
	RayTracer engine;

	engine.Construct(RayTracer::imageWidth, RayTracer::imageHeight, 4, 4);
	engine.Start();

	return 0;
}
