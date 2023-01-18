#include "lambertian.h"

Lambertian::Lambertian(const Color &a) : albedo(a) {}

bool Lambertian::Scatter(
    const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vec3 scatterDirection = rec.normal + Vec3::RandomUnitVector();

    // Catch degenerate scatter direction
    // to avoid a random unit vector being the exact opposite as the normal
    // This would lead to a zero sum, resulting in a bug
    if (scatterDirection.IsNearZero())
        scatterDirection = rec.normal;

    scattered = Ray(rec.point, scatterDirection);
    attenuation = albedo;

    return true;
}