#include <iostream>
#include "utils.hpp"

int main() {
    float degre, radian;
    saisir("Saisir un angle en radian : ", radian);
    trigonometrie::conversionRadianToDegre(radian, degre);
    affiche("L'angle en degre est : ", degre, " pour l'angle en radian : ", radian);
    return 0;
}