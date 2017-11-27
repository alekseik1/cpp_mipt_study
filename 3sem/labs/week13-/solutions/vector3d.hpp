#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <ostream>

class vector3d {
public:
    const static vector3d X;
    const static vector3d Y;
    const static vector3d Z;
    double x;
    double y;
    double z;
    const static vector3d ZERO;

    vector3d();
    vector3d(double x, double y, double z);

    vector3d operator+(const vector3d& other) const;
    friend vector3d operator-(const vector3d& v);
    vector3d operator-(const vector3d& other) const;

    friend vector3d operator*(const vector3d& v, double k);
    friend vector3d operator*(double k, const vector3d& v);
    double operator*(const vector3d& other) const;
    double operator*(const vector3d* other) const;
    bool operator==(const vector3d& other) const;
    bool operator==(const vector3d* other) const;
    bool operator!=(const vector3d& other) const;
    double length();
    vector3d operator^(const vector3d& other) const;
    friend std::ostream& operator<<(std::ostream& os, const vector3d& v);

    vector3d normalize();

};

// TODO: дописать

#endif
