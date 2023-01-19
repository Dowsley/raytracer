#ifndef METAL_H
#define METAL_H

#include "../abstract/material.h"
#include "../ray.h"
#include "../color.h"
#include "../hit_record.h"

class Metal : public Material
{
    public:
        Color albedo;
        double fuzzinessPerc;

        Metal(const Color &a, double f);

        virtual bool Scatter(
            const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered
        ) const override;
};

#endif