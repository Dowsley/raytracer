#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

using std::shared_ptr;

#include "abstract/hittable.h"
#include "abstract/material.h"
#include "vec3.h"
#include "hit_record.h"

class Sphere : public Hittable {
    public:
        Sphere();
        Sphere(Vec3 center, double r, shared_ptr<Material> m);

        virtual bool CheckHit(
            const Ray &r, double tMin, double tMax, HitRecord &rec) const override;

        Vec3 center;
        double radius;
        shared_ptr<Material> material; // TODO: Move this to Hittable base class
};

#endif