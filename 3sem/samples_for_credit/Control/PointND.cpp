//
// Created by aleksei on 09.12.17.
//

#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include "PointND.hpp"

PointND::PointND(unsigned n, std::initializer_list<double> coords) {
    if(coords.size() != n) {
        throw("Not enough coords to unpack!");
    }
    _N = n;
    _X = (double*) calloc(n, sizeof(double));
    int i = 0;
    for(auto& x : coords) {
        _X[i] = x;
        ++i;
    }
}

PointND::~PointND() {
    if(_X != nullptr) {
        free(_X);
        _X = nullptr;
    }
}

PointND::PointND(): PointND(1, {0.0})
{}

PointND::PointND(int n) {
    _N = n;
    _X = (double*) calloc(n, sizeof(double));
    for(int i = 0; i < n; i++) {
        _X[i] = 0;
    }
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
