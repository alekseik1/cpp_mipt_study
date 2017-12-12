//
// Created by aleksei on 12.12.17.
//

#include<gtest/gtest.h>
#include "SquareMatrix.hpp"

TEST(Matrix, SimpleCreation) {
    Matrix<char> m(5);
}

TEST(Matrix, getSize) {
    for(int i = 1; i < 5; i++) {
        Matrix<double> m(i);
        ASSERT_EQ(m.size(), i);
    }
}

TEST(Matrix, SettersAndGetters) {
    Matrix<int> m(5);
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m.size(); j++) {
            m.set(i, j, i+j);
        }
    }
    // TEST
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m.size(); j++) {
            ASSERT_EQ(m.get(i, j), i+j);
        }
    }
}

TEST(Matrix, Determinant) {
    Matrix<int> m(3);
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m.size(); j++) {
            m.set(i, j, i+j);
        }
    }
    ASSERT_EQ(m.det(), 0);

    Matrix<double> m1(2);
    // Задаем матрицу
    m1.set(0, 0, 2.);
    m1.set(0, 1, 5.);
    m1.set(1, 0, 1.);
    m1.set(1, 1, 9.);
    ASSERT_EQ(m1.det(), 13);
}

TEST(Matrix, DeterminantNonNumber) {
    Matrix<char> m3(2);
    m3.set(0, 0, 'a');
    m3.set(0, 1, '0');
    m3.set(1, 0, '0');
    m3.set(1, 1, 'b');
    ASSERT_EQ((char) m3.det(), '"');    // That's okey, we can mult chars and cast to double
}

TEST(Matrix, MatrixOutput) {
    Matrix<int> m1(4);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i+j);
        }
    }
    std::cout << m1;
}

TEST(Matrix, MatrixSum) {
    Matrix<int> m1(4);
    Matrix<int> m2(4);
    Matrix<int> m3(3);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i);
            m2.set(i, j, j);
        }
    }
    Matrix<int> res = m1+m2;
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res.size(); j++) {
            ASSERT_EQ(res.get(i, j), i+j);
        }
    }
    // Drop, if dims not equal
    ASSERT_ANY_THROW(m1+m3);
}

TEST(Matrix, DISABLED_MatrixSub) {
    Matrix<int> m1(7);
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i);
        }
    }
    m1 = -m1;
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            ASSERT_EQ(m1.get(i, j), -i);
        }
    }
}