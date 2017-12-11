//
// Created by aleksei on 12.12.17.
//

#include "ComplexNumber.hpp"

ComplexNumber::ComplexNumber(double _re, double _im) {
    re = _re;
    im = _im;
}

ComplexNumber::ComplexNumber(double _re): ComplexNumber(_re, 0)
{}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) {
    return ComplexNumber(this->re + other.re, this->im + other.im);
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

ComplexNumber operator*(double k, const ComplexNumber& number) {
    return {k*number.re, k*number.im};
}

ComplexNumber operator*(const ComplexNumber& number, double k) {
    return k*number;
}