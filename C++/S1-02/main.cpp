#include <iostream>
#include "sort.hpp"
#include <vector>


int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11, 90, 34, 7};
    std::cout << "Original array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    sortAlgo(arr);

    std::cout << "Sorted array:   ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
