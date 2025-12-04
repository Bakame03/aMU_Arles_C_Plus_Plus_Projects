#include <iostream>
#include <vector>
#include "outils.hpp"

int main() {
    std::vector<RGB> colors;
    unsigned nbColors;
    saisirNbColors(nbColors);
    saisirColors(colors, nbColors);
    afficherColors_rbg_to_hex(colors);
    return 0;
}