#include <iostream>

std::string saisirName(std::string msg) {
    std::string name;
    std::cout << msg;
    std::getline(std::cin, name);
    return name;
}

unsigned saisirAge(std::string msg) {
    unsigned age;
    std::cout << msg;
    std::cin >> age;
    return age;
}

int main() {
    std::string name = saisirName("\nEntrez votre nom : ");
    unsigned age = saisirAge("\nEntrez votre age : ");
    std::cout << "\nBonjour " << name << ", vous avez " << age << " ans.\n" << std::endl;
    return 0;
}