#include "ray.h"

Ray::Ray() :origin(Vec3(0,0,0)), dir(Vec3(0,0,0)) {}
Ray::Ray(const Vec3& origin, const Vec3& direction)
    : origin(origin), dir(direction)
{}

Vec3 Ray::GetOrigin() const  { return origin; }
Vec3 Ray::GetDirection() const { return dir; }

Vec3 Ray::At(double t) const {
    return origin + t * dir;
}
