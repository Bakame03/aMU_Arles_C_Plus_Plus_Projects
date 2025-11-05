#include <iostream>
#include "../utils.hpp"

int main(){
    int age;
    do{
        saisir("Saisir votre age : ", age);
        if(age < 0){
            std::cout << "L'age ne peut pas etre negatif. Veuillez ressaisir." << std::endl;
        }
    }while(age < 0);
    verifyAge(age);
    return 0;
}