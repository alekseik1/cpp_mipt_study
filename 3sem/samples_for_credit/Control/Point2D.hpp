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
    PointND(int n, ...);

    virtual ~PointND();
};


#endif //WEEK11_POINT2D_HPP
