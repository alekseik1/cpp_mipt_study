//
// Created by aleksei on 09.12.17.
//

#include "VectorND.hpp"

VectorND::VectorND(int n): PointND(n)
{}

VectorND::VectorND(int n, std::initializer_list<double> coords): PointND(n, coords)
{}