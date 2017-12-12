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
};


#endif //WEEK11_MATRIX_HPP
