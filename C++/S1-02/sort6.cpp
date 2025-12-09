#include <iostream>
#include <vector>
#include "sort.hpp"

void sortAlgo(std::vector<int>& arr) {
    size_t n = arr.size(); 
    for (size_t i = 1; i < n; ++i) {
        
        bool condition = true; 
        size_t j = i;       

        while (condition && j >= 1) {
            condition = (arr[j - 1] > arr[j]);
            if (condition) {
                std::swap(arr[j - 1], arr[j]);
            }
            j--;
        }
    }
}