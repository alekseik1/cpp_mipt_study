//
// Created by aleksei on 12.12.17.
//

#include <cmath>
#include "ComplexNumber.hpp"

ComplexNumber::ComplexNumber(double _re, double _im) {
    re = _re;
    im = _im;
}

ComplexNumber::ComplexNumber(double _re): ComplexNumber(_re, 0)
{}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) {
    return {this->re + other.re, this->im + other.im};
}

ComplexNumber::ComplexNumber(): ComplexNumber(0, 0)
{}

ComplexNumber ComplexNumber::operator-() {
    return {-this->re, -this->im};
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &other) {
    return {re - other.re, im - other.im};
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) {
    return {re*other.re - im*other.im, re*other.im + im*other.re};
}

ComplexNumber ComplexNumber::operator*(double k) {
    return ComplexNumber(k*re, k*im);
}

ComplexNumber operator*(double k, const ComplexNumber& number) {
    return ComplexNumber(k*number.re, k*number.im);
}

ComplexNumber ComplexNumber::operator^(int n) {
    ComplexNumber res = *this;
    for(int i = 1; i < n; i++) {
        res = res*(*this);
    }
    return res;
}

double ComplexNumber::abs() {
    return sqrt(re*re + im*im);
}

double ComplexNumber::arg() {
    return acos(re/abs());
}