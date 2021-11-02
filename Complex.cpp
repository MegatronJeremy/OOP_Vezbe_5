//
// Created by Jocke on 10/10/2020.
//

#include "Complex.h"

#include <cmath>

namespace complex {
    std::ostream &operator<<(std::ostream &os, const Complex &c) {
        return os << "(" << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i)";
    }

    double Complex::getReal() const {
        return real;
    }

    void Complex::setReal(double real) {
        Complex::real = real;
    }

    double Complex::getImag() const {
        return imag;
    }

    void Complex::setImag(double imag) {
        Complex::imag = imag;
    }

    double real(const Complex &c) {
        return c.real;
    }

    double imag(const Complex &c) {
        return c.imag;
    }

    Complex operator+(const Complex &c1, const Complex &c2) {
        //(a + bi) + (c + di) = (a + c) + (b + d)i
        return {c1.real + c2.real, c1.imag + c2.imag};
    }

    Complex &Complex::operator+=(const Complex &c) {
        return *this = *this + c;
    }

    Complex &Complex::operator-=(const Complex &c) {
        this->real -= c.real;
        this->imag -= c.imag;
        return *this;
    }

    Complex operator-(Complex c1, Complex c2) {
        return c1 -= c2;
    }

    Complex Complex::operator*(const Complex &c) const {
        // (a + bi) * (c + di) = ac + adi + bci + bdi^2 = (ac - bd) + (ad + bc)i
        return {real * c.real - imag * c.imag, real * c.imag + imag * c.real};
    }

    double abs(const Complex &c) {
        return std::sqrt(c.real * c.real + c.imag * c.imag);
    }

    double arg(const Complex &c) {
        return std::atan2(c.imag, c.real);
    }

    Complex Complex::operator~() const {
        return {real, -imag};
    }

    Complex Complex::operator+() const {
        return *this;
    }

    bool operator==(const Complex &c1, const Complex &c2) {
//      return c1.real == c2.real && c1.imag == c2.imag;
        return std::abs(c1.real - c2.real) < Complex::delta && std::abs(c1.imag - c2.imag) < Complex::delta;
    }

    bool operator!=(const Complex &c1, const Complex &c2) {
        return !(c1 == c2);
    }

    std::istream &operator>>(std::istream &is, Complex &c) {
        std::cout << "Provide real and imag parts";
        return is >> c.real >> c.imag;
    }

    Complex operator ""i(unsigned long long val) {
        return Complex(0, val);
    }

    Complex operator ""i(long double val) {
        return Complex(0, val);
    }
}