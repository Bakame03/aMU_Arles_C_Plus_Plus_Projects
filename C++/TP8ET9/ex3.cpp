#include <iostream>
#include "../utils.hpp"

int main() {
    double a, b, c;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    echange2(&a, &b);
    std::cout << "After echange2, a: " << a << ", b: " << b << std::endl;
    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;
    ordonne3(&a, &b, &c);
    std::cout << "After ordonne3, a: " << a << ", b: " << b << ", c: " << c << std::endl;   
    return 0;
}