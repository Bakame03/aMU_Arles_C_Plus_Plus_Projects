#include <iostream>
#include "utils.hpp"

int main() {
    int n1, n2;
    saisir("\nSaisir un premier nombre n1= ", n1);
    saisir("\nSaisir un deuxieme nombre n2= ", n2);
    std::cout << "\nAvant echange, n1= "<<n1<<" et n2= "<<n2<<"\n"<< std::endl;
    swap(n1, n2);
    std::cout << "\nApres echange, n1= "<<n1<<" et n2= "<<n2<<"\n"<< std::endl;
    return 0;
}