//
// Created by aleksei on 09.12.17.
//

#include <gtest/gtest.h>
#include "PointND.hpp"


TEST(PointND, PointND_Empty_Create) {
    PointND p;

    for(int i = 0; i < p.getDim(); ++i) {
        ASSERT_DOUBLE_EQ(p.get(i), 0.0);
    }
}

TEST(PointND, PointND_Create_With_Params_TestParams) {
    PointND p1(3, {1.0, 2.0, 3.0});

    ASSERT_DOUBLE_EQ(p1.get(0), 1.0);
    ASSERT_DOUBLE_EQ(p1.get(1), 2.0);
    ASSERT_DOUBLE_EQ(p1.get(2), 3.0);
}

TEST(PointND, PointND_Params_Size_Mismatch) {
    ASSERT_ANY_THROW(PointND p2(100, {1, 2, 3}));
}

TEST(PointND, PointND_Create_Big_Dimensions_Default_Params) {
    PointND p1(100);
    for(int i = 0; i < 100; i++) {
        ASSERT_EQ(p1.get(i), 0);
    }
}

TEST(PointND, PointND_Create_Five_dim_with_params) {
    PointND p1(5, {0.123, 0.234, 0.345, 0.456, 0.567});
    ASSERT_DOUBLE_EQ(p1.get(0), 0.123);
    ASSERT_DOUBLE_EQ(p1.get(1), 0.234);
    ASSERT_DOUBLE_EQ(p1.get(2), 0.345);
    ASSERT_DOUBLE_EQ(p1.get(3), 0.456);
    ASSERT_DOUBLE_EQ(p1.get(4), 0.567);
}