#include <iostream>
#include "../utils.hpp"
#include <vector>

int main() {
    std::vector<int> tab{13, 10, 2, 14};
    int somme = 0;
    float moyenne = 0.0f;
    afficheElementsTableau(tab);
    somme = getSommeElementsTableau(tab, somme);
    std::cout << "Somme des elements du tableau : " << somme << std::endl;
    getMoyenneElementsTableau(tab, moyenne);
    std::vector<int> tab2 = tab;
    int lastElement{};
    deleteLastElement(tab2, lastElement);
    std::vector<int> tab3 = tab;
    int firstElement{};
    deleteFirstElement(tab3, firstElement);

    std::vector<int> tab4{13, 0, 0, 10, 2, 0, 14, 0};
    removeZeros(tab4);
    afficheElementsTableau(tab4);
    return 0;
}