#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "../abstract/material.h"

class Lambertian : public Material
{
    public:
        Lambertian(const Color &a);

        virtual bool Scatter(
            const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered
        ) const override;

    public:
        Color albedo;
};

#endif