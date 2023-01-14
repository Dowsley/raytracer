#include "camera.h"

Ray Camera::GetRay(double u, double v) const
{
    return Ray(originPoint, lowerLeftCornerPoint + u*horizontalDir + v*verticalDir - originPoint);
}