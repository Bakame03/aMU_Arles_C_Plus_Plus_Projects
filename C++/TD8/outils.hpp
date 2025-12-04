#ifndef __OUTILS__
#define __OUTILS__
#include <string>
#include <vector>

struct RGB {
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

struct HSL {
    double h;
    double s;
    double l;
};

using Hex = std::string;

void saisirNbColors(unsigned &nbColors);
void saisirColors(std::vector<RGB> &colors, unsigned nbColors);
void afficherColors_rbg_to_hex(const std::vector<RGB> &colors);

#endif // __OUTILS__