#include <iostream>
#include "Ratio.hpp"

int main(){

    Ratio r1(-3,4);
    Ratio r2(7);
    Ratio r3;

    r1.affecter(2,3);
    r2.afficher(std::cout);
    std::cout << r3.valeurReelle() << std::endl;

    return 0;
}