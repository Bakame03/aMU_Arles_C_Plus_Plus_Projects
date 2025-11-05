#include <iostream>
#include "../utils.hpp"

int main() {
    int nbre1;
    saisir("Saisir un nombre entier : ", nbre1);
    verifyPositiveNegativeNull(nbre1);
    return 0;
}