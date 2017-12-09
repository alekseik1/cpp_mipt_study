//
// Created by aleksei on 09.12.17.
//

#ifndef WEEK11_POINT2D_HPP
#define WEEK11_POINT2D_HPP


class PointND {
private:
    double* _X;
    int _N;
public:
    PointND();

    PointND(unsigned n, std::initializer_list<double> coords);

    double get(int n) const;

    int getDim() const noexcept;

    virtual ~PointND();//
};


#endif //WEEK11_POINT2D_HPP
