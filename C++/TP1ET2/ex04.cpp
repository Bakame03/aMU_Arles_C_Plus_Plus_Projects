#include <iostream>
#include "utils.hpp"

int main() {
    int n1, n2, n3;
    saisir("\nSaisir un premier nombre n1= ", n1);
    saisir("\nSaisir un deuxieme nombre n2= ", n2);
    saisir("\nSaisir un troisieme nombre n3= ", n3);
    affiche("\nAvant echange, n1= ", n1, " et n2= ", n2, " et n3= ", n3);
    swap(n1, n2, n3);
    affiche("\nApres echange, n1= ", n1, " et n2= ", n2, " et n3= ", n3);
    return 0;
}