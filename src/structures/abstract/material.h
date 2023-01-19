#ifndef MATERIAL_H
#define MATERIAL_H

struct HitRecord;

#include "../ray.h"
#include "../color.h"
#include "../vec3.h"

class Material
{
public:
    static Vec3 Reflect(const Vec3 &v, const Vec3 &n);
    static Vec3 Refract(const Vec3 &r, const Vec3 &n, double etaOverEtaPrime);
    static double CalculateReflectance(double cos, double refractionRatio);
    virtual bool Scatter(
        const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered
    ) const = 0;
};

#endif