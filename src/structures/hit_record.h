
#ifndef HIT_RECORD_H
#define HIT_RECORD_H

#include "vec3.h"
#include "ray.h"

struct HitRecord {
    Vec3 point;
    Vec3 normal;
    double t;
    bool frontFace;
    void setFaceNormal(const Ray &r, const Vec3 &outwardNormal);
};

#endif