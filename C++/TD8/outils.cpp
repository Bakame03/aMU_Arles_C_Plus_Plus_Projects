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
        int v0 = v % 16;
        int v1 = (v - v0) / 16; 
        hexString += hexTable[v1]; 
        hexString += hexTable[v0]; 
    }
    
    std::cout << hexString << std::endl;
}

void afficherColors_rbg_to_hex(const std::vector<RGB> &colors) {
    std::cout << "Colors in Hex format:" << std::endl;
    for (size_t i = 0; i < colors.size(); ++i) {
        rgbToHex(colors[i]);
    }
}

void rgbToHsl(const RGB &color) {
    double r = color.r / 255.0;
    double g = color.g / 255.0;
    double b = color.b / 255.0;

    double max = std::max({r, g, b}); //to verify apparement le max et min c'est deux valeurs!!!!!!!
    double min = std::min({r, g, b});
    double h, s, l;
    l = (max + min) / 2.0;

    if (max == min) {
        h = s = 0; 
    } else {
        double d = max - min;
        s = l > 0.5 ? d / (2.0 - max - min) : d / (max + min);
        if (max == r) {
            h = (g - b) / d + (g < b ? 6 : 0);
        } else if (max == g) {
            h = (b - r) / d + 2; //to verify here apparement we use fmod() !!!!! to  get division entierre!!!!
        } else {
            h = (r - g) / d + 4;
        }
        h /= 6;
    }

    h *= 360; // Convert to degrees
    std::cout << "HSL(" << h << ", " << s * 100 << "%, " << l * 100 << "%)" << std::endl;
}

