//
// Created by aleksei on 09.12.17.
//

#include "VectorND.hpp"

VectorND::VectorND(int n, const PointND& start, const PointND& finish): _N(n) {
    for(int i = 0; i < n; i++) {
        _X[i] = finish.get(i) - start.get(i);
    }
}

VectorND::VectorND(int n): VectorND(n, PointND(n), PointND(n))
{}

VectorND::~VectorND() {

}

int VectorND::getDim() const noexcept {
    return _N;
}