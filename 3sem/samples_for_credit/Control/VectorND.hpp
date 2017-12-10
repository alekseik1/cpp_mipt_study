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
    virtual ~VectorND();
    VectorND operator+(const VectorND& other);
    VectorND operator-(const VectorND& other);
    VectorND operator-();
    double operator*(const VectorND& other);
    friend VectorND operator*(double k, const VectorND& v);
    friend VectorND operator*(const VectorND& v, double k);
    int getDim() const noexcept;
};


#endif //WEEK11_VECTORND_HPP
