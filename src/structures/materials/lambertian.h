#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "../abstract/material.h"
#include "../ray.h"
#include "../color.h"
#include "../hit_record.h"
class Lambertian : public Material
{
    public:
        Color albedo;

        Lambertian(const Color &a);

        virtual bool Scatter(
            const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered
        ) const override;
};

#endif