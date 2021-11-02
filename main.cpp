#include "Complex.h"

using namespace complex;

int main() {

    Complex c1 {1, -2}, c2 {2, 3};
    std::cout << real(c1) << " | " << imag(c1) << std::endl;
    std::cout << "C1 je: " << c1 << std::endl;
    std::cout << "C2: " << c2 << std::endl;
    std::cout << "C1 * C2: " << (c1 * c2) << std::endl;
    std::cout << "C1 after modification: " << c1 << std::endl;
    std::cout << "abs(C1): " << abs(c1) << std::endl;
    std::cout << "arg(C1): " << arg(c1) << std::endl;
    std::cout << "~C1: " << ~c1 << std::endl;
    c1 = {1/10. + 4/6., 0.5};
    c2 = {46/60., 0.5};
    std::cout << "C1 == C2: " << (c1 == c2) << std::endl;
    std::cout << "C1 != C2: " << (c1 != c2) << std::endl;

    std::cin >> c1;
    std::cout << "C1: " << c1 << std::endl;

    Complex c = 3.i; //(0 + 3i)
    std::cout << "C: " << c << std::endl;

    return 0;
}