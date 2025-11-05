#include <iostream>
#include "../utils.hpp"
#include <vector>
#include <string>

int main() {
    int nbreNotes;
    float moyenne;
    std::vector<double> notes;
    std::vector<double> coefficients;
    saisir("Entrez le nombre de notes : ", nbreNotes);
    readDoubleVector("Entrez la note qui se trouve entre les intervalles", notes, nbreNotes, 0, 20);
    readDoubleVector("Entrez le coefficient qui se trouve entre les intervalles", coefficients, nbreNotes, 0, 100);
    getmoyenne(notes, coefficients, moyenne);
    affiche("La moyenne est : ", moyenne);
    return 0;
}