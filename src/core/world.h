#ifndef WORLD_H
#define WORLD_H

#include "../structures/abstract/hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class World
{
    public:
        World();
        World(shared_ptr<Hittable> object);

        void Clear();
        void Add(shared_ptr<Hittable> object);

        bool CheckHit(const Ray &r, double tMin, double tMax, HitRecord &rec) const;

        static World GenerateRandom();

    private:
        std::vector<shared_ptr<Hittable>> objects;
};

#endif
