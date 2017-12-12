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