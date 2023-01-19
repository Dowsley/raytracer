#include "metal.h"

#include "../../utils/geometry.h"

Metal::Metal(const Color &a, double f): albedo(a), fuzzinessPerc(f < 1 ? f : 1) {}

bool Metal::Scatter(
    const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vec3 scatterDirection = Material::Reflect(rayIn.GetDirection().UnitVector(), rec.normal);
    scattered = Ray(rec.point, scatterDirection + fuzzinessPerc*Geometry::RandomPointInUnitSphere());
    attenuation = albedo;

    return true;
}