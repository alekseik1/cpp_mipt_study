//
// Created by aleksei on 12.12.17.
//

#include <gtest/gtest.h>
#include "ComplexNumber.hpp"
#include <cmath>

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

TEST(ComplexNumber, ComplexNumber_MultByDouble) {
    ComplexNumber c1(1, 2);
    ComplexNumber c2 = c1*2.0;
    ComplexNumber c3 = 3*c1;
    ASSERT_DOUBLE_EQ(c2.re, 2);
    ASSERT_DOUBLE_EQ(c2.im, 4);

    ASSERT_DOUBLE_EQ(c3.re, 3);
    ASSERT_DOUBLE_EQ(c3.im, 6);
}

TEST(ComplexNumber, ComplexNumber_MultTwoComplex) {
    ComplexNumber c1(1, 2);
    ComplexNumber c2(-1, 3);
    ComplexNumber c3 = c1*c2;

    ASSERT_DOUBLE_EQ(c3.re, -7);
    ASSERT_DOUBLE_EQ(c3.im, 1);
}

TEST(ComplexNumber, ComplexNumber_PowerComplex) {
    ComplexNumber c1(-1, 2);
    ComplexNumber c2 = c1^2;

    ASSERT_DOUBLE_EQ(c2.re, -3);
    ASSERT_DOUBLE_EQ(c2.im, -4);
}

TEST(ComplexNumber, ComplexNumber_AbsoluteValue) {
    ComplexNumber c1(3, 4);
    ComplexNumber c2(5, 12);
    ASSERT_DOUBLE_EQ(c1.abs(), 5);
    ASSERT_DOUBLE_EQ(c2.abs(), 13);
}

TEST(ComplexNumber, ComplexNumber_ArgumentValue) {
    ComplexNumber c1(5, 7);
    ASSERT_DOUBLE_EQ(c1.arg(), acos(5/sqrt(5*5+7*7)));
}

TEST(ComplexNumber, ComplexNumber_ComplexEquality) {
    ComplexNumber c1(2, 3);
    ComplexNumber c2(5, 6);
    ComplexNumber c3(2, 3);
    ASSERT_TRUE(c1 != c2);
    ASSERT_TRUE(c1 == c3);
}

// ДАЛЬШЕ ИДУТ ТЕСТЫ МОИХ ХОТЕЛОК. Основное уже реализовано

TEST(ComplexNumber, ComplexNumber_SumComplexWithDouble) {
    ComplexNumber c1(2, 5);
    double other = 5;
    ComplexNumber c2 = c1 + other;
    ComplexNumber c3 = other + c1;
    ASSERT_DOUBLE_EQ(c2.re, 7);
    ASSERT_DOUBLE_EQ(c2.im, 5);
    ASSERT_DOUBLE_EQ(c3.re, 7);
    ASSERT_DOUBLE_EQ(c3.im, 5);
}
