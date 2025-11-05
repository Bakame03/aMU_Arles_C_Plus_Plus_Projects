#include <iostream>
#include "utils.hpp"

int main() {
    char mot[80];
    std::cout << "Entrez un mot ne depassant pas 80 caracteres: ";
    bool over80 = false;
    do{
        std::cin >> mot;
        for(size_t i = 0; i < 80; i++){
            if(i > 79){
                over80 = true;
                std::cout << "Le mot depasse 80 caracteres. Veuillez ressaisir un mot: ";
                break;
            }
        }
    }while(over80 == true);
    reverseOrdreCaractere(mot, 80);
    std::cout << "Mot inverse: " << mot << std::endl;
    return 0;
}