#include <iostream>
#include "../utils.hpp"
#include <string>

int main(){
    std::string chaine{};
    int nbreCaracteres{};
    saisir("Entrez une chaîne de caractères : ", chaine);
    getNombreCaracteres(chaine, nbreCaracteres);
    std::cout << "Le nombre de voyelles dans la chaîne est : " << nbreCaracteres << std::endl;
    return 0;
}