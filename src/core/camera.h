#ifndef CAMERA_H
#define CAMERA_H

#include "../structures/ray.h"

class Camera
{
    public:
        Camera() {
            double aspectRatio = 16.0 / 9.0;
            double viewportHeight = 2.0;
            double viewportWidth = aspectRatio * viewportHeight;
            double focalLength = 1.0;

            originPoint = Vec3(0, 0, 0);
            horizontalDir = Vec3(viewportWidth, 0.0, 0.0);
            verticalDir = Vec3(0.0, viewportHeight, 0.0);
            lowerLeftCornerPoint = originPoint - horizontalDir/2 - verticalDir/2 - Vec3(0, 0, focalLength);
        }

        Ray GetRay(double u, double v) const;

    private:
        Vec3 originPoint;
        Vec3 lowerLeftCornerPoint;
        Vec3 horizontalDir;
        Vec3 verticalDir;
};

#endif