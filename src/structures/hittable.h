#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.h"
#include "ray.h"
#include "hit_record.h"

class Hittable {
    public:
        virtual bool CheckHit(const Ray &r, double tMin, double tMax, HitRecord &rec) const = 0;
};

#endif