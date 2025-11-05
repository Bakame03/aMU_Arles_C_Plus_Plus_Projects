#include <iostream>
#include "../utils.hpp"

int main(){
    int joursNaissance, moisNaissance, anneeNaissance, jourActuel, moisActuel, anneeActuel;
    saisir("Entrez votre jour de naissance : ", joursNaissance);
    saisir("Entrez votre mois de naissance : ", moisNaissance);
    saisir("Entrez votre annee de naissance : ", anneeNaissance);
    saisir("Entrez le jour actuel : ", jourActuel);
    saisir("Entrez le mois actuel : ", moisActuel);
    saisir("Entrez l'annee actuelle : ", anneeActuel);
    verifyAge(joursNaissance, moisNaissance, anneeNaissance, jourActuel, moisActuel, anneeActuel);
    return 0;
}