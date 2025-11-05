#include <iostream>
#include "../utils.hpp"

int main() {
    int year, month, day;
    saisir("Veuillez saisir une annee: ", year);
    saisir("Veuillez saisir un mois: ", month);
    saisir("Veuillez saisir un jour: ", day);
    valideYearMonthDay(year, month, day);
    return 0;
}