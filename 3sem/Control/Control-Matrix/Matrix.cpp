//
// Created by aleksei on 12.12.17.
//

#include "Matrix.hpp"

template<typename T>
void Matrix<T>::delete_array() {
    if(_matrix != nullptr) {
        for (int r = 0; r < _n; r++)
            delete[] _matrix[r];
        delete[] _matrix;
        _matrix = nullptr;
    }
}

template<typename T>
void Matrix<T>::init_array(int n, int m) {
    _matrix = new T*[n];
    for(int s=0; s < n; s++)
        _matrix[s] = new T[m];
}

template<typename T>
Matrix<T>::Matrix(int n, int m): _n(n), _m(m) {
    init_array(n, m);
}

template<typename T>
Matrix<T>::~Matrix() {
    delete_array();
}