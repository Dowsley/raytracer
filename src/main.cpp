#define PROGRESS_NUM_BARS 30

#include <iostream>

#include "utils/index.h"
#include "structures/index.h"
#include "core/index.h"

class RayTracer
{
private:
    Writer *writer;

    /* Image */
    const double aspectRatio = 16.0 / 9.0;
    const int imageWidth = 400;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

    /* Camera */
    const double viewportHeight = 2.0;
    const double viewportWidth = aspectRatio * viewportHeight;
    const double focalLength = 1.0;

    /* Directions */
    const Vec3 horizontalDir = Vec3(viewportWidth, 0, 0);
    const Vec3 verticalDir = Vec3(0, viewportHeight, 0);

    /* Points */
    const Vec3 originPoint = Vec3(0, 0, 0);
    const Vec3 lowerLeftCornerPoint = originPoint - horizontalDir/2 - verticalDir/2 - Vec3(0, 0, focalLength);

    /* Objects (centers) */
    const Vec3 sphere1 = Vec3(0, 0, -1);

public:
	RayTracer() {
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
                // This gets a percentage so we can traverse the viewport.
                auto u = double(i) / (imageWidth);
                auto v = double(j) / (imageHeight);

                Ray r = Ray(originPoint, lowerLeftCornerPoint + u*horizontalDir + v*verticalDir - originPoint);
                Color c = GetRayColor(r);

                writer->WriteRow(c);
            }
            LogProgress((double) (j+1) / imageHeight);
        }
    }

    // 0 roots: No hit
    // 1 root: Tangent (one) hit
    // 2 roots: Secant, two hits
    double HitSphere(const Vec3 &center, double radius, const Ray &r) const
    {
        Vec3 oc = r.GetOrigin() - center;
        double a = r.GetDirection().LengthSquared(); // Equivalent of vector.dot(vector);
        double b = 2.0 * oc.Dot(r.GetDirection());
        double c = oc.LengthSquared() - radius * radius;
        double discriminant = b*b - 4*a*c;
        if (discriminant < 0.0) {
            return -1.0;
        } else {
            return (-b - sqrt(discriminant) ) / (2.0*a);
        }
    }

    Color GetRayColor(const Ray &r) const
    {
        double t = HitSphere(sphere1, 0.5, r);
        if (t > 0.0) {
            Vec3 normal = (r.At(t) - sphere1).UnitVector();
            return Color(0.5 * (1 + Vec3(normal.x(), normal.y(), normal.z())));
        }
        Vec3 unitDirection = r.GetDirection().UnitVector();
        t = 0.5 * (unitDirection.y() + 1.0);
        return Color((1.0 - t) * Color(0.9, 0.3, 0.5) + t * Color(0.5, 0.7, 1.0)); // lerp
    }

    void LogProgress(float perc) const
    {
        if (!(perc >= 0.0f && perc <= 1.0f)) {
            throw std::invalid_argument("Progress percentage value must be between 0.0f and 1.0f range.");
        }

        int progress_scaled = Arithmetics::scale(perc, 0.0, 1.0, 0.0, PROGRESS_NUM_BARS);

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
	RayTracer rayTracer = RayTracer();

	rayTracer.Render();

    return 0;
}
