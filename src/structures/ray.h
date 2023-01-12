#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    public:
        Ray();
        Ray(const Vec3& origin, const Vec3& direction);

        Vec3 GetOrigin() const;
        Vec3 GetDirection() const;

        Vec3 At(double t) const;

    private:
        Vec3 origin;
        Vec3 dir;
};

#endif
