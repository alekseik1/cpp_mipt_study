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