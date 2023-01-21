#ifndef CAMERA_H
#define CAMERA_H

#include "../structures/ray.h"
#include "../structures/vec3.h"

class Camera
{
    public:
        Camera(
            Vec3 lookFromPoint,
            Vec3 lookToPoint,
            Vec3 viewUpDir, 
            double verticalFOVDegrees,
            double aspectRatio,
            double aperture,
            double focusDist
        );

        Ray GetRay(double s, double t) const;

    private:
        Vec3 originPoint;
        Vec3 lowerLeftCornerPoint;
        Vec3 horizontalDir;
        Vec3 verticalDir;
        double lensRadius;
        Vec3 u, v, w;
};

#endif