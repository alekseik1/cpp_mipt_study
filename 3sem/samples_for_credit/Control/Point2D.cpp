//
// Created by aleksei on 09.12.17.
//

#include <cstdlib>
#include <stdio.h>
#include <cstdarg>
#include <iostream>
#include "Point2D.hpp"

PointND::PointND() {
    PointND(1, {0.0});
}

PointND::PointND(unsigned n, std::initializer_list<double> coords) {
    _N = n;
    _X = new double[n];
    int i = 0;
    for(auto& x : coords) {
        _X[i] = x;
        ++i;
    }
}

PointND::~PointND() {
    delete[] _X;
    _X = nullptr;
}

double PointND::get(int n) const {
    if(n >= _N) {
        throw("n is more than vector dimension!");
    } else {
        return _X[n];
    }
}

int PointND::getDim() const noexcept {
    return _N;
}
