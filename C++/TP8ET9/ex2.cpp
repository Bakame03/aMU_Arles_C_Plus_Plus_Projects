#include <iostream>
#include <string.h>

int main(int argc, char * argv[]) {
    if(strcmp(argv[0], "./hello") == 0) {
        std::cout << "Hello, World!" << std::endl;
    } else {
        std::cout << "Bonjour le monde!" << std::endl;
    }
    return 0;
}