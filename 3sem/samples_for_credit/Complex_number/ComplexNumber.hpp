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
    ComplexNumber operator*(double k);
    ComplexNumber operator^(int n);
    double abs();
    double arg();
    bool operator==(const ComplexNumber& other);
    bool operator!=(const ComplexNumber& other);
    // Обязательная часть закончена. Дальше -- мои хотелки
    // Хочу, чтобы обычный double можно было прибавлять к комплексу!
    ComplexNumber operator+(double other);
    ComplexNumber operator-(double other);
    // Всеми любимые плюсы!
    void operator++();
    void operator+=(const ComplexNumber& other);
    void operator--();
    void operator-=(const ComplexNumber& other);
    void operator*=(const ComplexNumber& other);
    void operator*=(double k);
    // TODO: Сделать еще деление
};

ComplexNumber operator*(double k, const ComplexNumber& number);
// Мои хотелки. Хочу, чтобы обычный double можно было прибавлять к комплексу, да еще и в обратном порядке!
ComplexNumber operator+(double other, const ComplexNumber& number);
ComplexNumber operator-(double other, const ComplexNumber& number);


#endif //WEEK11_COMPLEX_NUMBER_HPP
