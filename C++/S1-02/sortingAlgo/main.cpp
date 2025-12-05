#include <vector>
#include <iostream>

void quickSort(std::vector<int>& v) {
    if (v.size() >= 1) {
        int pivot = v[0];
        std::vector<int> v1, v2, v3;

        for (int x : v) {
            if (x < pivot)
                v1.push_back(x);       
            else if (x > pivot)
                v3.push_back(x);     
            else // x == pivot
                v2.push_back(x);      
        }

        quickSort(v1);
        quickSort(v3);

        v = v1;
        v.insert(v.end(), v2.begin(), v2.end());
        v.insert(v.end(), v3.begin(), v3.end());
    }
}

int main() {
    std::vector<int> v = {5, 3, 1, 2, 7, 6, 7, 5, 1, 3, 4, 0, 9, 8};

    quickSort(v);

    for (int x : v)
        std::cout << " " << x;

    std::cout << std::endl;
    return 0;
}