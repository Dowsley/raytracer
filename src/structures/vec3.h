#ifndef Vec3_H
#define Vec3_H

#include <fstream>

class Vec3
{
    public:
        Vec3();
        Vec3(double x, double y, double z);

        // No, I'm not gonna respect standard names here.
        double x();
        double y();
        double z();

        Vec3 operator-() const;
        double operator[](int i) const;
        double& operator[](int i);

        Vec3& operator+=(const Vec3 &v);
        Vec3& operator+=(const double t);
        Vec3& operator*=(const double t);
        Vec3& operator/=(const double t);

        friend Vec3 operator+(const Vec3 &u, const Vec3 &v);
        friend Vec3 operator-(const Vec3 &u, const Vec3 &v);
        friend Vec3 operator*(const Vec3 &u, const Vec3 &v);
        friend Vec3 operator*(double t, const Vec3 &v);
        friend Vec3 operator*(const Vec3 &v, double t);
        friend Vec3 operator/(Vec3 v, double t);
        friend std::ostream& operator<<(std::ostream &out, const Vec3 &v);

        double Length() const;
        double LengthSquared() const;
        double Dot(const Vec3 &v);
        Vec3 Cross(const Vec3 &v);
        Vec3 UnitVector();

    protected:
        double e[3];
};

#endif
