#include <iostream>
#include "../utils.hpp"
#include <vector>
#include <string>

int main() {
    std::string mot;
    saisir("Saisir un mot : ", mot);
    palindrome(mot);
    return 0;
}