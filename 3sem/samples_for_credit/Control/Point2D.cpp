//
// Created by aleksei on 09.12.17.
//

#include "Point2D.hpp"

PointND::PointND(int n, ...) {
    _N = n;
    _X = (double*) calloc(n, sizeof(double));
}

PointND::~PointND() {
    free(_X);
}