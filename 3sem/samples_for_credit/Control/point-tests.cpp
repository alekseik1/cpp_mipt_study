//
// Created by aleksei on 09.12.17.
//

#include <gtest/gtest.h>
#include "Point2D.hpp"

TEST(PointND, EmptyCreate) {
    PointND p;

    for(int i = 0; i < p.getDim(); ++i) {
        ASSERT_FLOAT_EQ(p.get(i), 0.0);
    }
}

TEST(PointND, CreateWithParams) {
    PointND p(3, {1.0, 2.0, 3.0});

    ASSERT_FLOAT_EQ(p.get(0), 1.0);
    ASSERT_FLOAT_EQ(p.get(1), 2.0);
    ASSERT_FLOAT_EQ(p.get(2), 3.0);
}