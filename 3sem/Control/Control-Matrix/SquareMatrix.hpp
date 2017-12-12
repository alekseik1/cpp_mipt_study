//
// Created by aleksei on 12.12.17.
//

#ifndef WEEK11_MATRIX_HPP
#define WEEK11_MATRIX_HPP

#include <iostream>
#include <ostream>
#include<cmath>

template<typename T>
class Matrix {
private:
    T** _matrix;
    int _n;

    void init_array(int n) {
        _matrix = new T*[n];
        for(int s=0; s < n; s++)
            _matrix[s] = new T[n];
    }

    void delete_array() {
        if(_matrix != nullptr) {
            for (int r = 0; r < _n; r++)
                delete[] _matrix[r];
            delete[] _matrix;
            _matrix = nullptr;
        }
    }

    // TODO: Из-за этого метода нельзя использовать Matrix для нечисленных типов (и типов, не приводимых к double). Грустно!
    double _determ(T** Arr, int size) const {
        try {
            (double) T();
        } catch(error_t e) {
            throw(e);
        }
        int i,j;
        double det = 0;
        T** matr;
        if(size==1) {
            det = Arr[0][0];
        }
        else if(size==2) {
            det = Arr[0][0]*Arr[1][1] - Arr[0][1]*Arr[1][0];
        }
        else {
            matr=new T*[size-1];
            for(i=0; i < size; ++i) {
                for(j=0; j < size-1; ++j) {
                    if(j < i)
                        matr[j] = Arr[j];
                    else
                        matr[j] = Arr[j+1];
                }
                det += pow((double)-1, (i+j)) * _determ(matr, size-1) * Arr[i][size-1];
            }
            delete[] matr;
        }
        return det;
    }

public:
    Matrix(int n): _n(n) {
        init_array(n);
    }

    virtual ~Matrix() {
        delete_array();
    }

    int size() const {
        return _n;
    }

    T get(int i, int j) const {
        return _matrix[i][j];
    }

    void set(int i, int j, const T& value) {
        if(i >= _n || j >= _n) {
            throw("Dimension problems!");
        }
        _matrix[i][j] = value;
    }

    double det() const {
        return _determ(_matrix, _n);
    }

    Matrix operator+(const Matrix& other) const {
        if(_n != other.size()) {
            throw("Dimension problems!");
        }
        Matrix res(_n);
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < _n; j++) {
                res.set(i, j, get(i, j) + other.get(i, j));
            }
        }
        return res;
    }

    Matrix operator-() const {
        Matrix res(_n);
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < _n; j++) {
                res.set(i, j, -_matrix[i][j]);
            }
        }
        return res;
    }

    Matrix operator*(double k) const {
        Matrix<T> res(_n);
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < _n; j++) {
                res.set(i, j, k*_matrix[i][j]);
            }
        }
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        if(_n != other.size()) {
            throw("Dimension problems!");
        }
        Matrix<T> res(_n);
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < _n; j++) {
                // Суммируем строки/столбцы
                T tmp_sum = 0;
                for(int k = 0; k < _n; k++) {
                    tmp_sum += get(i, k)*other.get(k, j);
                }
                res.set(i, j, tmp_sum);
            }
        }
        return res;
    }

    // Опасное присваивание
    void operator=(const Matrix& other) {
        delete_array();
        init_array(other.size());
        for(int i = 0; i < other.size(); i++) {
            for(int j = 0; j < other.size(); j++) {
                set(i, j, other.get(i, j));
            }
        }
    }

    Matrix operator^(int n) const {
        Matrix<T> res(_n);
        for(int i = 0; i < size(); i++) {
            for(int j = 0; j < size(); j++) {
                res.set(i, j, get(i, j));
            }
        }
        for(int i = 1; i < n; i++) {
            res = res*(*this);
        }
        return res;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m.size(); j++) {
            os << m.get(i, j) << ' ';
        }
        os << std::endl;
    }
    return os;
}

template<typename T>
Matrix<T> operator*(double k, const Matrix<T>& matrix) {
    return matrix*k;
}


#endif //WEEK11_MATRIX_HPP
