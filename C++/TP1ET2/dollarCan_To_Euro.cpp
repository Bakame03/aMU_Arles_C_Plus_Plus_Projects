#include <iostream>
#include "utils.hpp"

int main() {
    float euros, dollars;
    saisir("Entrez le montant en dollars canadiens: ", dollars);
    conversionMoney::conversionUSDToEUR(dollars, euros);
    affiche("Montant en euros: ", euros);
    return 0;
}