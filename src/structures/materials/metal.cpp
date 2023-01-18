#include "metal.h"

#include <stdexcept>

Metal::Metal(const Color &a, double f): albedo(a), fuzzinessPerc(f < 1 ? f : 1) {}


Vec3 Metal::Reflect(const Vec3 &v, const Vec3 &n) const
{
    // TODO: Put the explanation in a README section and reference it here
    // Scatter ray formula: https://raytracing.github.io/images/fig-1.11-reflection.jpg
    return v - 2 * v.Dot(n) * n;
}

bool Metal::Scatter(
    const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vec3 scatterDirection = Reflect(rayIn.GetDirection().UnitVector(), rec.normal);
    scattered = Ray(rec.point, scatterDirection + fuzzinessPerc*Geometry::RandomPointInUnitSphere());
    attenuation = albedo;

    return true;
}