#include "vector3d.hpp"

#include <cmath>

const vector3d vector3d::X = {1, 0, 0};
const vector3d vector3d::Y = {0, 1, 0};
const vector3d vector3d::Z = {0, 0, 1};
const vector3d vector3d::ZERO = {0, 0, 0};

// TODO: дописать

vector3d::vector3d(): x(0), y(0), z(0) {}
vector3d::vector3d(double x, double y, double z): x(x), y(y), z(z) {}

vector3d vector3d::operator+(const vector3d& other) const {
    return {this->x + other.x, this->y + other.y, this->z + other.z};
}

vector3d operator*(const vector3d& v, double k) {
    return {v.x*k, v.y*k, v.z*k};
}

vector3d operator*(double k, const vector3d& v) {
    return {v.x*k, v.y*k, v.z*k};
}

double vector3d::operator*(const vector3d &other) const {
    return x*other.x + y*other.y + z*other.z;
}
double vector3d::operator*(const vector3d *other) const {
    return x*other->x + y*other->y + z*other->z;
}

bool vector3d::operator==(const vector3d &other) const {
    return (x == other.x && y == other.y && z == other.z);
}

bool vector3d::operator==(const vector3d *other) const {
    return (x == other->x && y == other->y && z == other->z);
}

bool vector3d::operator!=(const vector3d &other) const {
    return !(other == this);
}

vector3d operator-(const vector3d& v) {
    return {-v.x, -v.y, -v.z};
}

vector3d vector3d::operator-(const vector3d &other) const {
    return *this + (-other);
}

double vector3d::length() {
    return sqrt(*this**this);
}

vector3d vector3d::normalize() {
    double ro = length();
    return {x/ro, y/ro, z/ro};
}

vector3d vector3d::operator^(const vector3d &other) const {
    return {y*other.z - other.y*z, -(x*other.z - z*other.x), x*other.y-y*other.x};
}

std::ostream& operator<<(std::ostream &os, const vector3d &v) {
    os << '{' << v.x << ", " << v.y << ", " << v.z << '}';
    return os;
}