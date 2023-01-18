
#ifndef HIT_RECORD_H
#define HIT_RECORD_H

#include <memory>

using std::shared_ptr;

#include "vec3.h"
#include "ray.h"
#include "abstract/material.h"

struct HitRecord {
    Vec3 point;
    Vec3 normal;
    shared_ptr<Material> material;
    double t;
    bool frontFace;
    void setFaceNormal(const Ray &r, const Vec3 &outwardNormal);
};

#endif