#include <iostream>
#include <expected> // This is the C++23 header
#include <string>

// A function that returns an int (success) OR a string (error)
std::expected<int, std::string> divide(int a, int b) {
    if (b == 0) {
        return std::unexpected("Don't divide by zero, buddy!");
    }
    return a / b;
}

int main() {
    auto result = divide(10, 0);

    if (result) {
        std::cout << "Result: " << result.value() << "\n";
    } else {
        std::cout << "Error: " << result.error() << "\n";
    }
    
    return 0;
}