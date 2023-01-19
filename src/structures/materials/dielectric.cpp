#include "dielectric.h"

#include <cmath>

#include "../../utils/random.h"

Dielectric::Dielectric(const Color &a, double ri)
    : refractionIndex(ri), albedo(a) {} 

bool Dielectric::Scatter(const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    attenuation = albedo;
    double refractionRatio = rec.frontFace ? (1.0 / refractionIndex) : refractionIndex;

    Vec3 unitDir = rayIn.GetDirection().UnitVector();
    double cosTheta = fmin((-unitDir).Dot(rec.normal), 1.0);
    double sinTheta = sqrt(1.0 - cosTheta * cosTheta);

    bool cannotRefract = refractionRatio * sinTheta > 1.0;
    Vec3 direction;

    if (cannotRefract || Material::CalculateReflectance(cosTheta, refractionRatio) > Random::RandomDouble())
        direction = Material::Reflect(unitDir, rec.normal);
    else
        direction = Material::Refract(unitDir, rec.normal, refractionRatio);

    scattered = Ray(rec.point, direction);
    return true;
}