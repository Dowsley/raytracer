#include "vec3.h"

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

double Vec3::Dot(const Vec3 &v)
{
    return e[0] * v[0]
        + e[1] * v[1]
        + e[2] * v[2];
}

Vec3 Vec3::Cross(const Vec3 &v)
{
    return Vec3(e[1] * v[2] - e[2] * v[1],
                e[2] * v[0] - e[0] * v[2],
                e[0] * v[1] - e[1] * v[0]);
}

Vec3 Vec3::UnitVector()
{
    return *this / this->Length();
}

Vec3 operator+(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]); }
Vec3 operator-(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]); }
Vec3 operator*(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]); }
Vec3 operator*(double t, const Vec3 &v) { return Vec3(t*v[0], t*v[1], t*v[2]); }
Vec3 operator*(const Vec3 &v, double t) { return t * v; }
Vec3 operator/(Vec3 v, double t) { return (1/t) * v; }
std::ostream& operator<<(std::ostream &out, const Vec3 &v) { return out << v[0] << ' ' << v[1] << ' ' << v[2]; }
