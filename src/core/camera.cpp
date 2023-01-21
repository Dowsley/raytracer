#include "camera.h"

#include <cmath>

#include "../utils/geometry.h"

Camera::Camera(
    Vec3 lookFromPoint,
    Vec3 lookAtPoint,
    Vec3 viewUpDir,
    double verticalFovDegrees,
    double aspectRatio,
    double aperture,
    double focusDist
) {
    double theta = Geometry::DegreesToRadians(verticalFovDegrees);
    double fovRatio = tan(theta / 2);
    double viewportHeight = 2.0 * fovRatio;
    double viewportWidth = aspectRatio * viewportHeight;

    w = (lookFromPoint - lookAtPoint).UnitVector();
    u = viewUpDir.Cross(w).UnitVector();
    v = w.Cross(u);

    originPoint = lookFromPoint;
    horizontalDir = focusDist * viewportWidth * u;
    verticalDir = focusDist * viewportHeight * v;
    lowerLeftCornerPoint = originPoint - horizontalDir / 2 - verticalDir / 2 - focusDist*w;

    lensRadius = aperture / 2;
}

Ray Camera::GetRay(double s, double t) const
{
    Vec3 rd = lensRadius * Geometry::RandomPointInUnitDisk();
    Vec3 offset = u * rd.x() + v * rd.y();
    return Ray(originPoint + offset, lowerLeftCornerPoint + s*horizontalDir + t*verticalDir - originPoint - offset);
}