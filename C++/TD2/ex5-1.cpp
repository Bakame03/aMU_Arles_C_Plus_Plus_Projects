#include <iostream>
#include "../utils.hpp"

int main() {
    int year;
    do {
        saisir("Veuillez saisir une annee: ", year);
        if (year < 0) {
            std::cout << "L'annee saisie n'est pas valide. Veuillez reessayer." << std::endl;
        }
    } while (year < 0);
    anneBissextile(year);
    return 0;
}