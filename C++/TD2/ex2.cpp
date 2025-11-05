#include <iostream>
#include "../utils.hpp"

int main(){
    int nbre, intervalle1, intervalle2;
    saisir("Saisir un nombre entier : ", nbre);
    saisirIntrvalles("Saisir un intervalle (2 entiers) : ", intervalle1, intervalle2);
    verifyNbreEntreIntervalle(nbre, intervalle1, intervalle2);
    return 0;
}