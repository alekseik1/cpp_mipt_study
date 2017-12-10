//
// Created by aleksei on 09.12.17.
//

#ifndef WEEK11_VECTORND_HPP
#define WEEK11_VECTORND_HPP

#include "PointND.hpp"


class VectorND: public PointND {

public:
    VectorND(int n, std::initializer_list<double> coords);
    explicit VectorND(int n);
    VectorND operator+(const VectorND& other);
    VectorND operator-(const VectorND& other);
    VectorND operator-();
    double operator*(const VectorND& other);
    void setCoord(int i, double c);
};

VectorND operator*(double k, const VectorND& v);
VectorND operator*(const VectorND& v, double k);


#endif //WEEK11_VECTORND_HPP
