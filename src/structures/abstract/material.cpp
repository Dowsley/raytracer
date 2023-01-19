#include "material.h"

#include <cmath>

Vec3 Material::Reflect(const Vec3 &v, const Vec3 &n)
{
    // TODO: Put the explanation in a README section and reference it here
    // Scatter ray formula: https://raytracing.github.io/images/fig-1.11-reflection.jpg
    return v - 2 * v.Dot(n) * n;
}

Vec3 Material::Refract(const Vec3 &rIn, const Vec3 &n, double etaOverEtaPrime)
{
    double cosTheta = fmin((-rIn).Dot(n), 1.0);
    Vec3 rOutPerpendicular =  etaOverEtaPrime * (rIn + cosTheta*n);
    Vec3 rOutParallel = -sqrt(fabs(1.0 - rOutPerpendicular.LengthSquared())) * n;
    return rOutPerpendicular + rOutParallel;
}


double Material::CalculateReflectance(double cos, double refractionRatio)
{
    // Use Schlick's polynomial approximation for reflectance.
    auto r0 = (1 - refractionRatio) / (1 + refractionRatio);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cos), 5);
}