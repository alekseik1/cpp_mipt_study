//
// Created by aleksei on 09.12.17.
//

#ifndef WEEK11_POINT2D_HPP
#define WEEK11_POINT2D_HPP


#include <initializer_list>

class PointND {
protected:
    int _N;
    double* _X = nullptr;
public:
    PointND();

    PointND(unsigned n, std::initializer_list<double> coords);

    explicit PointND(int n);

    virtual double get(int n) const;

    virtual int getDim() const noexcept;

    virtual ~PointND();
};


#endif //WEEK11_POINT2D_HPP
