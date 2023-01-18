#ifndef MATERIAL_H
#define MATERIAL_H

struct HitRecord;

class Material
{
public:
    virtual bool Scatter(
        const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered
    ) const = 0;
};

#endif