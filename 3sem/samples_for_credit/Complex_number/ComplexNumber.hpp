//
// Created by aleksei on 12.12.17.
//

#ifndef WEEK11_COMPLEX_NUMBER_HPP
#define WEEK11_COMPLEX_NUMBER_HPP

/**
 * Класс комплексного числа.
 */
class ComplexNumber {
public:
    double im;
    double re;
    ComplexNumber(double _re, double _im);
    ComplexNumber(double _re);
    ComplexNumber();
    ComplexNumber operator+(const ComplexNumber& other);
    ComplexNumber operator-();
    ComplexNumber operator-(const ComplexNumber& other);
    ComplexNumber operator*(const ComplexNumber& other);
};

ComplexNumber operator*(double k, const ComplexNumber& number);
ComplexNumber operator*(const ComplexNumber& number, double k);


#endif //WEEK11_COMPLEX_NUMBER_HPP
