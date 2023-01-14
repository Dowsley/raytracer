#include "sphere.h"

#include <cmath>

// 0 roots: No hit
// 1 root: Tangent (one) hit
// 2 roots: Secant, two hits
bool Sphere::CheckHit(const Ray &r, double tMin, double tMax, HitRecord &rec) const
{
    Vec3 oc = r.GetOrigin() - center;
    auto a = r.GetDirection().LengthSquared(); // Equivalent of vector.Dot(vector);
    auto halfB = oc.Dot(r.GetDirection());
    auto c = oc.LengthSquared() - radius*radius;

    auto discriminant = halfB*halfB - a*c;
    if (discriminant < 0) {
         return false;
    }
    auto sqrtd = std::sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-halfB - sqrtd) / a;
    if (root < tMin || tMax < root) {
        root = (-halfB + sqrtd) / a;
        if (root < tMin || tMax < root)
            return false;
    }

    rec.t = root;
    rec.point = r.At(rec.t);
    Vec3 outwardNormal = (rec.point - center) / radius;
    rec.setFaceNormal(r, outwardNormal);

    return true;
}