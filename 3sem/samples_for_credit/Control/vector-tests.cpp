//
// Created by aleksei on 09.12.17.
//

#include <gtest/gtest.h>
#include "VectorND.hpp"

TEST(VectorND, VectorND_Empty_Creation) {
    for(int i = 1; i < 100; i++) {
        VectorND v(i);
        ASSERT_EQ(v.getDim(), i);
    }
}

TEST(VectorND, VectorND_Coord_Setter) {
    VectorND v(3, {1, 1, 1});
    v.setCoord(0, 5.0);
    v.setCoord(1, 10.0);
    v.setCoord(2, -15.0);
    ASSERT_DOUBLE_EQ(v.get(0), 5.0);
    ASSERT_DOUBLE_EQ(v.get(1), 10.0);
    ASSERT_DOUBLE_EQ(v.get(2), -15.0);
}

TEST(VectorND, VectorND_Mult_By_Double) {
    VectorND p(3, {1, 1, 1});
    for(int i = 0; i < 100; i++) {
        VectorND p1 = p*i;
        VectorND p2 = i*p;
        for(int j = 0; j < p1.getDim(); j++) {
            ASSERT_DOUBLE_EQ(p1.get(j), i);
            ASSERT_DOUBLE_EQ(p2.get(j), i);
        }
    }
}

TEST(VectorND, VectorND_Vector_Sum) {
    VectorND p1(5, {1, 2, 3, 4, 5});
    VectorND p2(5, {2, 3, 4, 5, 6});
    VectorND ps1 = p1+p2;
    for(int i = 0; i < p1.getDim(); i++) {
        ASSERT_DOUBLE_EQ(ps1.get(i), i+1+i+2);
    }
}

TEST(VectorND, VectorND_Vector_Sum_With_Different_Dims) {
    VectorND p1(5, {1, 2, 3, 4, 5});
    VectorND p2(4, {2, 3, 4, 5});
    ASSERT_ANY_THROW(VectorND ps1 = p1+p2);
}

TEST(VectorND, VectorND_Negative_One_Vector) {
    VectorND p1(4, {1, 2, -2, -3});
    VectorND p2 = -p1;
    for(int i = 0; i < p1.getDim(); i++) {
        ASSERT_DOUBLE_EQ(p2.get(i), -p1.get(i));
    }
}

TEST(VectorND, VectorND_Vector_Minus_Vector) {
    VectorND p1(5, {1, 2, 3, 4, 5});
    VectorND p2(5, {0, 1, 2, 3, 4});
    VectorND p3 = p1 - p2;
    for(int i = 0; i < p1.getDim(); i++) {
        ASSERT_DOUBLE_EQ(p3.get(i), 1);
    }
}

TEST(VectorND, VectorND_Vector_Minus_Vector_With_Different_Dims) {
    VectorND p1(5, {1, 2, 3, 4, 5});
    VectorND p2(4, {2, 3, 4, 5});
    ASSERT_ANY_THROW(VectorND ps1 = p1-p2);
}