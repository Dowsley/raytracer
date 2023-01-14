#include "world.h"

World::World(shared_ptr<Hittable> object) { Add(object); }

void World::Clear() { objects.clear(); }
void World::Add(shared_ptr<Hittable> object) { objects.push_back(object); }

bool World::CheckHit(const Ray &r, double tMin, double tMax, HitRecord &rec) const
{
    HitRecord tempRecord;
    bool hitAny = false;
    auto closestSoFar = tMax;

    for (const auto &object : objects) {
        if (object->CheckHit(r, tMin, closestSoFar, tempRecord)) {
            hitAny = true;
            closestSoFar = tempRecord.t;
            rec = tempRecord;
        }
    }

    return hitAny;
}
