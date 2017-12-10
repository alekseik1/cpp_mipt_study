//
// Created by aleksei on 09.12.17.
//

#include "VectorND.hpp"

VectorND::VectorND(int n): PointND(n)
{}

VectorND::VectorND(int n, std::initializer_list<double> coords): PointND(n, coords)
{}

void VectorND::setCoord(int i, double c) {
    if(i >= _N) {
        throw("Incorrect number of dim!");
    }
    _X[i] = c;
}

VectorND operator*(double k, const VectorND& v) {
    VectorND p(v.getDim());
    for(int i = 0; i < v.getDim(); i++) {
        p.setCoord(i, k*v.get(i));
    }
    return p;
}
VectorND operator*(const VectorND& v, double k) {
    VectorND p(v.getDim());
    for(int i = 0; i < v.getDim(); i++) {
        p.setCoord(i, k*v.get(i));
    }
    return p;
}