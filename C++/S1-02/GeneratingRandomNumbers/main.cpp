#include <cstdint>
#include <iostream>
#include <random>

int main() {
    static std::random_device rd; // To obtain a seed
    static std::mt19937 gen(rd()); // Standard generator
    int min = 0, max = 10;

    std::uniform_int_distribution<int> distrib(min, max);
    std::cout << "Min:␣" << min << "␣Max:␣" << max << std::endl;
    for (size_t k = 0; k < 8; k++) {
        int n = distrib(gen); // Random int from 0 to 10
        std::cout << n << "␣";
    }
    std::cout << std::endl;

    std::uniform_int_distribution<size_t> distrib2(min, max);
    for (size_t k = 0; k < 8; k++) {
        size_t n = distrib2(gen); // Random size_t from 0 to 10
        std::cout << n << "␣";
    }
    std::cout << std::endl;

    return 0;
}