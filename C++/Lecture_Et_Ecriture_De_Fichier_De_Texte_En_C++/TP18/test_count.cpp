#include <iostream>
#include <string>
#include <cctype>

static std::size_t utf8_strlen(const std::string &s) {
    std::size_t count = 0;
    for (size_t i = 0; i < s.length(); ) {
        unsigned char c = s[i];
        
        if ((c & 0xC0) != 0x80) {
            if (!std::isspace(c) && c != '\'' && c != '-') {
                count++;
            }
            
            if ((c & 0x80) == 0) {
                i += 1;
            } else if ((c & 0xE0) == 0xC0) {
                i += 2;
            } else if ((c & 0xF0) == 0xE0) {
                i += 3;
            } else if ((c & 0xF8) == 0xF0) {
                i += 4;
            } else {
                i += 1;
            }
        } else {
            i++;
        }
    }
    return count;
}

int main() {
    std::string word = "Principauté d'Andorre";
    
    std::cout << "Word: \"" << word << "\"" << std::endl;
    std::cout << "Byte length: " << word.length() << std::endl;
    std::cout << "UTF-8 letter count: " << utf8_strlen(word) << std::endl;
    
    // Manual count
    std::cout << "\nManual breakdown:" << std::endl;
    int manual = 0;
    for (char c : word) {
        if (!std::isspace(c) && c != '\'' && c != '-') {
            manual++;
            std::cout << c;
        }
    }
    std::cout << "\nManual count: " << manual << std::endl;
    
    return 0;
}
