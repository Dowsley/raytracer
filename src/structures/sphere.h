#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "hittable.h"
#include "hit_record.h"

class Sphere : public Hittable {
    public:
        Sphere() {}
        Sphere(Vec3 center, double r) : center(center), radius(r) {};

        virtual bool CheckHit(
            const Ray &r, double tMin, double tMax, HitRecord &rec) const override;

    public:
        Vec3 center;
        double radius;
};

#endif