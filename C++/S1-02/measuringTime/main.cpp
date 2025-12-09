#include <iostream>
#include <chrono>

int main() {
    std::chrono::steady_clock::time_point t_start =
        std::chrono::steady_clock::now();

    size_t sum = 0;
    for (int i = 1; i <= 10000; i++)
        sum += i;

    std::chrono::steady_clock::time_point t_end =
        std::chrono::steady_clock::now();
    size_t duration =
        std::chrono::duration_cast<std::chrono::microseconds>
        (t_end - t_start).count();

    std::cout << " The␣sum␣of␣1␣to␣10000␣is␣" << sum << std::endl;
    std::cout << " And␣it␣took␣" << duration <<
        "␣microseconds␣to␣calculate␣it␣" << std::endl;
    return 0;
}