#include <iostream>
#include <vector>
#include "outils.hpp"

// Definitions des fonctions utilitaires 

void saisirNbColors(unsigned &nbColors) {
    do{
        std::cout << "Enter the number of colors: ";
        std::cin >> nbColors;
        if(nbColors <= 0 || nbColors > 8) {
            std::cout << "The number of colors must be between 1 and 8. Please try again." << std::endl;
        }
    }while(nbColors <= 0 || nbColors > 8);
}

void checkRGBInterval(RGB &color) {
    do{
        std::cout<< "  Enter R (0-255): ";
        std::cin >> color.r;
        if(color.r < 0 || color.r > 255) {
            std::cout << "  R must be between 0 and 255. Please try again." << std::endl;
        }
    }while(color.r < 0 || color.r > 255);
    do{
        std::cout<< "  Enter G (0-255): ";
        std::cin >> color.g;
        if(color.g < 0 || color.g > 255) {
            std::cout << "  G must be between 0 and 255. Please try again." << std::endl;
        }
    }while(color.g < 0 || color.g > 255);
    do{
        std::cout<< "  Enter B (0-255): ";
        std::cin >> color.b;
        if(color.b < 0 || color.b > 255) {
            std::cout << "  B must be between 0 and 255. Please try again." << std::endl;
        }
    }while(color.b < 0 || color.b > 255);
}

void saisirColors(std::vector<RGB> &colors, unsigned nbColors) {
    colors.resize(nbColors);
    for (unsigned i = 0; i < nbColors; ++i) {
        std::cout << "Color " << (i + 1) << ":" << std::endl;
        checkRGBInterval(colors[i]);
    }
}

void rgbToHex(const RGB &color) {
    const std::string hexTable = "0123456789ABCDEF";
    unsigned int values[3] = {color.r, color.g, color.b};
    std::string hexString = "#";
    
    for(int i = 0; i < 3; i++) {
        unsigned int v = values[i];

        // Ensure value is within 0-255 range
        if (v < 0) v = 0;
        if (v > 255) v = 255;

        // 1. Find the second digit (remainder)
        int v0 = v % 16;
        
        // 2. Find the first digit (integer division)
        // Note: In C++, integer division drops decimals, so (v-v0)/16 is same as v/16
        int v1 = (v - v0) / 16; 

        // 3. Use the indices to pick from the table
        hexString += hexTable[v1]; // First digit (e.g., the 'F' in F0)
        hexString += hexTable[v0]; // Second digit (e.g., the '0' in F0)
    }
    
    std::cout << hexString << std::endl;
}

void afficherColors_rbg_to_hex(const std::vector<RGB> &colors) {
    std::cout << "Colors in Hex format:" << std::endl;
    for (size_t i = 0; i < colors.size(); ++i) {
        rgbToHex(colors[i]);
    }
}

