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
    std::cout << m1 << std::endl;
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

TEST(Matrix, MatrixUnoSub) {
    Matrix<int> m1(11);
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i);
        }
    }
    Matrix<int> m2 = -m1;
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            ASSERT_EQ(m2.get(i, j), -i);
        }
    }
}

TEST(Matrix, MatrixMultDouble) {
    Matrix<double> m1(5);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i*m1.size()+ j);
        }
    }
    Matrix<double> m2 = m1*5;
    Matrix<double> m3 = 5*m1;
    for(int i = 0; i < m2.size(); i++) {
        for(int j = 0; j < m2.size(); j++) {
            ASSERT_EQ(m2.get(i, j), 5*(i*m2.size()+ j));
            ASSERT_EQ(m3.get(i, j), 5*(i*m3.size()+ j));
        }
    }
}

TEST(Matrix, MatrixMultByMatrix) {
    Matrix<int> m1(2);
    Matrix<int> m2(2);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i*m1.size()+ j);
        }
    }
    for(int i = 0; i < m2.size(); i++) {
        for(int j = 0; j < m2.size(); j++) {
            m2.set(i, j, i*m2.size()+ j);
        }
    }
    Matrix<int> m3 = m1*m2;
    // Проверка
    ASSERT_EQ(m3.get(0, 0), 2);
    ASSERT_EQ(m3.get(0, 1), 3);
    ASSERT_EQ(m3.get(1, 0), 6);
    ASSERT_EQ(m3.get(1, 1), 11);
}

TEST(Matrix, MatrixPow) {
    Matrix<int> m1(2);
    // Устанавливаем значения
    m1.set(0, 0, 0);
    m1.set(0, 1, 1);
    m1.set(1, 0, 1);
    m1.set(1, 1, 1);
    Matrix<int> res = m1^2;
    // Проверка
    ASSERT_EQ(res.get(0, 0), 1);
    ASSERT_EQ(res.get(0, 1), 1);
    ASSERT_EQ(res.get(1, 0), 1);
    ASSERT_EQ(res.get(1, 1), 2);
}

TEST(Matrix, MatrixEquality) {
    Matrix<int> m1(2);
    Matrix<int> m2(2);
    Matrix<int> m3(2);
    Matrix<int> m4(5);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i+j);
        }
    }
    for(int i = 0; i < m2.size(); i++) {
        for(int j = 0; j < m2.size(); j++) {
            m2.set(i, j, i+j);
        }
    }
    for(int i = 0; i < m3.size(); i++) {
        for(int j = 0; j < m3.size(); j++) {
            m3.set(i, j, 0);
        }
    }
    for(int i = 0; i < m4.size(); i++) {
        for(int j = 0; j < m4.size(); j++) {
            m4.set(i, j, i+j);
        }
    }
    ASSERT_EQ(m1, m2);
    ASSERT_NE(m1, m3);
    ASSERT_NE(m1, m4);
}

TEST(Matrix, MatrixTranspose) {
    Matrix<int> m1(3);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i*m1.size() + j);
        }
    }
    Matrix<int> res = m1.trans();
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res.size(); j++) {
            ASSERT_EQ(res.get(j, i), i*res.size() + j);
        }
    }
}

TEST(Matrix, MatrixDivDouble) {
    Matrix<double> m1(2);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i*m1.size() + j);
        }
    }

    Matrix<double> m2 = m1 / 2;
    for(int i = 0; i < m2.size(); i++) {
        for(int j = 0; j < m2.size(); j++) {
            ASSERT_DOUBLE_EQ(m2.get(i, j), ((double) (i*m2.size() + j))/2);
        }
    }
}

TEST(Matrix, MatrixMinorPrint) {
    Matrix<double> m1(3);
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1.size(); j++) {
            m1.set(i, j, i*m1.size() + j);
        }
    }
    Matrix<double> m2 = m1.get_minor(1, 1);
    ASSERT_DOUBLE_EQ(m2.get(0, 0), 0);
    ASSERT_DOUBLE_EQ(m2.get(0, 1), 2);
    ASSERT_DOUBLE_EQ(m2.get(1, 0), 6);
    ASSERT_DOUBLE_EQ(m2.get(1, 1), 8);
}

TEST(Matrix, MatrixInverse) {
    Matrix<double> m1(2);
    // Задаем
    m1.set(0, 0, 0.);
    m1.set(0, 1, 1.);
    m1.set(1, 0, 1.);
    m1.set(1, 1, 1.);
    // Проверяем
    Matrix<double> res = m1.inverse();
    std::cout << res << std::endl;
    ASSERT_EQ(res.get(0, 0), -1);
    ASSERT_EQ(res.get(0, 1), 1);
    ASSERT_EQ(res.get(1, 0), 1);
    ASSERT_EQ(res.get(1, 1), 0);

    Matrix<double> m2(2);
    // Задаем матрицу
    m2.set(0, 0, 2.);
    m2.set(0, 1, 5.);
    m2.set(1, 0, 1.);
    m2.set(1, 1, 9.);
    Matrix<double> res2 = m2.inverse();
    ASSERT_DOUBLE_EQ(res2.get(0, 0), 9.0/13);
    ASSERT_DOUBLE_EQ(res2.get(0, 1), -5.0/13);
    ASSERT_DOUBLE_EQ(res2.get(1, 0), -1.0/13);
    ASSERT_DOUBLE_EQ(res2.get(1, 1), 2.0/13);
}