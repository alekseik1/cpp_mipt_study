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
        // FIXME: На int все плохо. Видимо, опять целочисленная арифметика
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
    explicit Matrix(int n): _n(n) {
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

    // TODO: Из-за этого метода нельзя использовать Matrix для нечисленных типов (и типов, не приводимых к double). Грустно!
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
    Matrix& operator=(const Matrix& other) {
        delete_array();
        init_array(other.size());
        for(int i = 0; i < other.size(); i++) {
            for(int j = 0; j < other.size(); j++) {
                set(i, j, other.get(i, j));
            }
        }
        return *this;
    }

    // TODO: Из-за этого метода нельзя использовать Matrix для типов, на которых нет умножения
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

    bool operator==(const Matrix& other) const {
        if(_n != other.size())
            return false;
        for(int i = 0; i < other.size(); i++) {
            for(int j = 0; j < other.size(); j++) {
                if(get(i, j) != other.get(i, j))
                    return false;
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    Matrix trans() const {
        Matrix res(_n);
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < _n; j++) {
                res.set(i, j, get(j, i));
            }
        }
        return res;
    }

    Matrix operator/(double k) const {
        return ((*this) * (1.0/k));
    }

    Matrix get_minor(int n, int m) const {
        Matrix minor_m(_n - 1);

        for(int i0 = 0; i0 < n; i0++) {
            for(int j0 = 0; j0 < m; j0++) { // верх лево
                minor_m.set(i0, j0, get(i0, j0));
            }
            for(int j0 = m+1; j0 < _n; j0++) {  // верх право
                minor_m.set(i0, j0-1, get(i0, j0));
            }
        }
        for(int i0 = n+1; i0 < _n; i0++) {
            for(int j0 = 0; j0 < m; j0++) { // низ лево
                minor_m.set(i0-1, j0, get(i0, j0));
            }
            for(int j0 = m+1; j0 < _n; j0++) {  // низ право
                minor_m.set(i0-1, j0-1, get(i0, j0));
            }
        }
        return minor_m;
    }

    // TODO: Из-за этого метода нельзя использовать Matrix для нечисленных типов (и типов, не приводимых к double). Грустно!
    Matrix inverse() {
        // Веселье начинается!
        if(_n == 1) {
            return *this / det();
        }
        Matrix res(_n);
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < _n; j++) {
                Matrix minor_m = get_minor(i, j);
                res.set(i, j, minor_m.det()*pow((double) -1, i+j));
            }
        }
        return res.trans()/det();
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
