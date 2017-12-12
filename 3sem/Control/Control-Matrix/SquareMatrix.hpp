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
    void init_array(int n);
    void delete_array();
public:
    Matrix(int n);
    virtual ~Matrix();
};


#endif //WEEK11_MATRIX_HPP
