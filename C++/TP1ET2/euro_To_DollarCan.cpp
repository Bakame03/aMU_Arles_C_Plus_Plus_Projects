#include <iostream>
#include "utils.hpp"

int main() {
    float euros, dollars;
    saisir("Entrez le montant en euros: ", euros);
    conversionMoney::conversionEURToUSD(euros, dollars);
    affiche("Montant en dollars: ", dollars);
    return 0;
}