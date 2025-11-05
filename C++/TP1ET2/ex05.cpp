#include <iostream>
#include "utils.hpp"

int main() {
    float degre, radian;
    saisir("Saisir un angle en degre : ", degre);
    trigonometrie::conversionDegreToRadian(degre, radian);
    affiche("L'angle en radian est : ", radian, " pour l'angle en degre : ", degre);
    return 0;
}