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
    double _determ(T** Arr, int size) {
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
        _matrix[i][j] = value;
    }

    double det() {
        return _determ(_matrix, _n);
    }
};


#endif //WEEK11_MATRIX_HPP
