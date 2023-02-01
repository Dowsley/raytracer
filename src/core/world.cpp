#include "world.h"

#include <memory>

using std::make_shared;

#include "../structures/materials/dielectric.h"
#include "../structures/materials/metal.h"
#include "../structures/materials/lambertian.h"

#include "../structures/sphere.h"

#include "../utils/random.h"

World::World() {};
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

World World::GenerateRandom()
{
    World world;

    auto groundMaterial = make_shared<Lambertian>(Color(0.5, 0.5, 0.5));
    world.Add(make_shared<Sphere>(Vec3(0, 1000,0), 1000, groundMaterial));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double chooseMat = Random::RandomDouble();
            Vec3 center(a + 0.9*Random::RandomDouble(), -0.2, b + 0.9*Random::RandomDouble());

            if ((center - Vec3(4, 0.2, 0)).Length() > 0.9) {
                shared_ptr<Material> sphereMaterial;

                if (chooseMat < 0.8) {
                    // Diffuse
                    Color albedo = Color::Random() * Color::Random();
                    sphereMaterial = make_shared<Lambertian>(albedo);
                    world.Add(make_shared<Sphere>(center, 0.2, sphereMaterial));
                } else if (chooseMat < 0.95) {
                    // Metal
                    Color albedo = Color::Random(0.5, 1);
                    double fuzz = Random::RandomDouble(0, 0.5);
                    sphereMaterial = make_shared<Metal>(albedo, fuzz);
                    world.Add(make_shared<Sphere>(center, 0.2, sphereMaterial));
                } else {
                    // Glass
                    Color albedo = Color(1,1,1);
                    sphereMaterial = make_shared<Dielectric>(albedo, 1.5);
                    world.Add(make_shared<Sphere>(center, 0.2, sphereMaterial));
                }
            }
        }
    }

    auto material1 = make_shared<Dielectric>(Color::Random(), 1.5);
    world.Add(make_shared<Sphere>(Vec3(0, -1, 0), 1.0, material1));

    auto material2 = make_shared<Lambertian>(Color(0.4, 0.2, 0.1));
    world.Add(make_shared<Sphere>(Vec3(-4, -1, 0), 1.0, material2));

    auto material3 = make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);
    world.Add(make_shared<Sphere>(Vec3(4, -1, 0), 1.0, material3));

    return world;
}
