#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "../abstract/material.h"
#include "../ray.h"
#include "../color.h"
#include "../hit_record.h"

class Dielectric : public Material
{
    public:
        double refractionIndex;
        Color albedo;

        Dielectric(const Color &a, double ri);

        virtual bool Scatter(
            const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered
        ) const override;
};

#endif