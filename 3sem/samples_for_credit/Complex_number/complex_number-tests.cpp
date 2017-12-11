//
// Created by aleksei on 12.12.17.
//

#include <gtest/gtest.h>
#include "ComplexNumber.hpp"

TEST(ComplexNumber, ComplexNumber_EmptyCreation) {
    ComplexNumber c;
    ASSERT_DOUBLE_EQ(c.re, 0);
    ASSERT_DOUBLE_EQ(c.im, 0);
}

TEST(ComplexNumber, ComplexNumber_ParamCreation) {
    ComplexNumber c1(1, -2);
    ComplexNumber c2(0.5);
    ASSERT_DOUBLE_EQ(c1.re, 1);
    ASSERT_DOUBLE_EQ(c1.im, -2);

    ASSERT_DOUBLE_EQ(c2.re, 0.5);
    ASSERT_DOUBLE_EQ(c2.im, 0);
}

TEST(ComplexNumber, ComplexNumber_SumTwoNumbers) {
    ComplexNumber c1(-0.5, 2);
    ComplexNumber c2(0.7, -3);
    ComplexNumber c3 = c1 + c2;
    ASSERT_DOUBLE_EQ(c3.re, 0.2);
    ASSERT_DOUBLE_EQ(c3.im, -1);
}

TEST(ComplexNumber, ComplexNumber_SubTwoNumbers) {
    ComplexNumber c1(1, 1);
    ComplexNumber c2(-0.5, 0.5);
    ComplexNumber c3 = c1 - c2;
    ASSERT_DOUBLE_EQ(c3.re, 1.5);
    ASSERT_DOUBLE_EQ(c3.im, 0.5);
}

// TODO: дописать тесты!!!!