#include "vec3.h"
#include "../utils/random.h"
#include "../utils/geometry.h"

#include <cmath>

Vec3::Vec3()
{
   e[0] = 0;
   e[1] = 0;
   e[2] = 0;
}

Vec3::Vec3(double x, double y, double z)
{
    e[0] = x;
    e[1] = y;
    e[2] = z;
}

double Vec3::x() { return e[0]; }
double Vec3::y() { return e[1]; }
double Vec3::z() { return e[2]; }


Vec3 Vec3::Random()
{
    return Vec3(Random::RandomDouble(), Random::RandomDouble(), Random::RandomDouble());
}

Vec3 Vec3::Random(double min, double max)
{
    return Vec3(Random::RandomDouble(min,max), Random::RandomDouble(min,max), Random::RandomDouble(min,max));
}

Vec3 Vec3::RandomUnitVector()
{
    return Geometry::RandomPointInUnitSphere().UnitVector();
}

Vec3 Vec3::operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
double Vec3::operator[](int i) const { return e[i]; }
double& Vec3::operator[](int i) { return e[i]; }

Vec3& Vec3::operator+=(const Vec3 &v)
{
    e[0] += v[0];
    e[1] += v[1];
    e[2] += v[2];
    return *this;
}

Vec3& Vec3::operator+=(const double t)
{
    e[0] += t;
    e[1] += t;
    e[2] += t;
    return *this;
}

Vec3& Vec3::operator*=(const double t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(const double t)
{
    return *this *= 1/t;
}

double Vec3::Length() const
{
    return sqrt(LengthSquared());
}

double Vec3::LengthSquared() const
{
    return (e[0]*e[0]) + (e[1]*e[1]) + (e[2]*e[2]);
}

double Vec3::Dot(const Vec3 &v) const
{
    return e[0] * v[0]
        + e[1] * v[1]
        + e[2] * v[2];
}

Vec3 Vec3::Cross(const Vec3 &v) const
{
    return Vec3(e[1] * v[2] - e[2] * v[1],
                e[2] * v[0] - e[0] * v[2],
                e[0] * v[1] - e[1] * v[0]);
}

Vec3 Vec3::UnitVector() const
{
    return *this / this->Length();
}

bool Vec3::IsNearZero() const
{
    const auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

Vec3 operator+(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]); }
Vec3 operator+(const Vec3 &u, double val) { return Vec3(u[0] + val, u[1] + val, u[2] + val); } 
Vec3 operator+(double val, const Vec3 &u) { return u + val; } 
Vec3 operator-(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]); }
Vec3 operator*(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]); }
Vec3 operator*(double t, const Vec3 &v) { return Vec3(t*v[0], t*v[1], t*v[2]); }
Vec3 operator*(const Vec3 &v, double t) { return t * v; }
Vec3 operator/(Vec3 v, double t) { return (1/t) * v; }
std::ostream& operator<<(std::ostream &out, const Vec3 &v) { return out << "Vec3(" << v[0] << ' ' << v[1] << ' ' << v[2] << ")"; }
