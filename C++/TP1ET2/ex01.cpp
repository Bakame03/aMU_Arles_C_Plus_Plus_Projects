#include <iostream>

int saisir(std::string msg) {
    int n;
    std::cout << msg;
    std::cin >> n;
    return n;
}

void afficheHeure(int h, int m, int s) {
    std::cout << "\nIl est --> "<<h<<":"<<m<<":"<<s<<"\n"<< std::endl;
}

int main() {
    
    int heure = saisir("\nEntrez une heure (0-23) : ");
    int minute = saisir("\nEntrez une minute (0-59) : ");
    int seconde = saisir("\nEntrez une seconde (0-59) : ");
    afficheHeure(heure, minute, seconde);
    return 0;
}