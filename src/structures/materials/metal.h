#ifndef METAL_H
#define METAL_H

#include "../abstract/material.h"

class Metal : public Material
{
    public:
        Metal(const Color &a, double f);

        Vec3 Reflect(const Vec3 &v, const Vec3 &n) const;
        virtual bool Scatter(
            const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered
        ) const override;

    public:
        Color albedo;
        double fuzzinessPerc;
};

#endif