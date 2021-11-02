//
// Created by Jocke on 10/10/2020.
//

#ifndef DEMO_COMPLEX_H
#define DEMO_COMPLEX_H

#include <iostream>

namespace complex {
    class Complex {

        //real + i * imag
        double real, imag;
        static constexpr const double delta = 0.001;
    public:
        /*Complex() : real(0), imag(0) {}
        Complex(double real) : real(real), imag(0) {}*/
        Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}

        friend std::ostream &operator<<(std::ostream &os, const Complex &c);

        double getReal() const;

        void setReal(double real);

        double getImag() const;

        void setImag(double imag);

        friend double real(const Complex &c);

        friend double imag(const Complex &c);

        friend Complex operator+(const Complex &c1, const Complex &c2);

        Complex &operator+=(const Complex &c);

        Complex &operator-=(const Complex &c);

        friend Complex operator-(Complex c1, Complex c2);

        Complex operator*(const Complex &c) const;

        friend double abs(const Complex &c);

        friend double arg(const Complex &c);

        Complex operator~() const;

        Complex operator+() const;

        friend bool operator==(const Complex &c1, const Complex &c2);

        friend bool operator!=(const Complex &c1, const Complex &c2);

        friend std::istream &operator>>(std::istream &is, Complex &c1);
    };

    Complex operator ""i(unsigned long long val);

    Complex operator ""i(long double val);
}

#endif //DEMO_COMPLEX_H
