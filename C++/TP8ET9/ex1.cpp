#include <iostream>

int main(){
    size_t taille;
    std::cout << "\nEntrez la taille du tableau : ";
    std::cin >> taille;
    double * tab = new double[taille];
    std::cout << "\nEntrez les " << taille << " valeurs du tableau :" << std::endl;
    for(size_t i = 0; i < taille; ++i){
        std::cout << "\nValeur " << i + 1 << " : ";
        std::cin >> tab[i];
    }
    double moyenneTailleValeurs = 0;
    for(size_t i = 0; i < taille; ++i){
        moyenneTailleValeurs += tab[i];
    }
    moyenneTailleValeurs /= static_cast<double>(taille);
    std::cout << std::endl;
    std::cout << "\nLa taille moyenne des valeurs du tableau est : " << moyenneTailleValeurs << std::endl;
    delete [] tab;
    return 0;
}