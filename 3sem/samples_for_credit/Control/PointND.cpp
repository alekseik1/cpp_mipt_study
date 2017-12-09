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

PointND::PointND(): PointND(1, {0.0})  // А-тя-тя, вот тут ты и попался, temporary object!
{}

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
