#include <iostream>
#include <fstream>
// #include <string>

int main() {
    std::string nomfichier = "file_test.txt";
    std::ifstream mon_fichier(nomfichier);
    if (mon_fichier.is_open()) {
        double valeur;
        mon_fichier >> valeur;
        // std::cout << "le contenu lu dans valeur: " << valeur << std::endl; // output le contenu lu dans valeur: 0.0
    } else 
        std::cerr << "Impossible d'ouvrir le fichier \"" << nomfichier << "\"" << std::endl;
    return 0;
}