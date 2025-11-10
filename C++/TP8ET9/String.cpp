#include <iostream>
#include <string>
#include "String.hpp"

void CreateString(String & str, const size_t size=256) {
    str.allocated_size = size;
    str.buffer = new char[size];
    str.buffer[0] = '\0';
}

void DisplayString(const String & str) {
    for (size_t i = 0; i < str.buffer[i] != '\0'; ++i) {
        std::cout << str.buffer[i];
    }
    std::cout << std::endl;
}

int StringLength(const String & str) {
    size_t length = 0;
    while (str.buffer[length] != '\0') {
        ++length;
    }
    return length;
}

void DestroyString(String & str) {
    delete[] str.buffer;
    str.buffer = nullptr;
    str.allocated_size = 0;
}

void GrowString(String & str, const size_t new_size) {
    if (new_size > str.allocated_size) {
        char* new_buffer = new char[new_size];
        size_t i = 0;
        while (str.buffer[i] != '\0') {
            new_buffer[i] = str.buffer[i];
            ++i;
        }
        new_buffer[i] = '\0';
        delete[] str.buffer;
        str.buffer = new_buffer;
        str.allocated_size = new_size;
    }
}
    