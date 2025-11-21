#include <iostream>
#include <vector>
#include "../utils.hpp"

int main() {
    std::vector<int> listeInt;
    getListeInt(listeInt);
    afficheListeIntTableau(listeInt);
    afficheListeIntTableauCroissant(listeInt);
    afficheListeIntTableauCroissantWithoutOccurences(listeInt);
    afficheListeIntTableauCroissantWithoutOccurencesUsingSTD_SORT(listeInt);

    return 0;
}