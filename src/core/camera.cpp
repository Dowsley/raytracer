#include "camera.h"

#include <cmath>

#include "../utils/geometry.h"

Camera::Camera(
    Vec3 lookFromPoint,
    Vec3 lookAtPoint,
    Vec3 viewUpDir,
    double verticalFovDegrees,
    double aspectRatio)
{
    double theta = Geometry::DegreesToRadians(verticalFovDegrees);
    double fovRatio = tan(theta / 2);
    double viewportHeight = 2.0 * fovRatio;
    double viewportWidth = aspectRatio * viewportHeight;

    auto w = (lookFromPoint - lookAtPoint).UnitVector();
    auto u = viewUpDir.Cross(w).UnitVector();
    auto v = w.Cross(u);

    originPoint = lookFromPoint;
    horizontalDir = viewportWidth * u;
    verticalDir = viewportHeight * v;
    lowerLeftCornerPoint = originPoint - horizontalDir / 2 - verticalDir / 2 - w;
}

Ray Camera::GetRay(double s, double t) const
{
    return Ray(originPoint, lowerLeftCornerPoint + s*horizontalDir + t*verticalDir - originPoint);
}