//
// Created by aleksei on 12.12.17.
//

#ifndef WEEK11_MATRIX_HPP
#define WEEK11_MATRIX_HPP

template<typename T>
class Matrix {
private:
    T** _matrix;
    int _n;
    int _m;
    void init_array(int n, int m);
    void delete_array();
public:
    Matrix(int n, int m);
    virtual ~Matrix();
};


#endif //WEEK11_MATRIX_HPP
