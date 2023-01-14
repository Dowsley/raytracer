#include "hit_record.h"

void HitRecord::setFaceNormal(const Ray &r, const Vec3 &outwardNormal) {
    frontFace = r.GetDirection().Dot(outwardNormal) < 0;
    normal = frontFace ? outwardNormal : -outwardNormal;
}