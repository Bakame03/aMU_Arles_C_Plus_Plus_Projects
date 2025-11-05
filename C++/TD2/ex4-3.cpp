#include <iostream>
#include "../utils.hpp"

int main(){
    int nbre;
    do{
        saisir("Veuillez saisir un nombre impair positif: ", nbre);
        if(nbre <= 0 || nbre % 2 == 0){
            std::cout << "Le nombre saisi n'est pas valide. Veuillez reessayer." << std::endl;
        }
    }while(nbre <= 0 || nbre % 2 == 0);
    return 0;
}