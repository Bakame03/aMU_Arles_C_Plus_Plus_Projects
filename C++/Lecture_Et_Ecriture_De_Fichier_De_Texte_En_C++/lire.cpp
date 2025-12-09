#include <iostream>
#include <fstream>

int main() {
    std::string nomfichier = "file_test.txt";
    std::ifstream mon_fichier(nomfichier);
    if (mon_fichier.is_open()) {
        std::string ligne;
        while (std::getline(mon_fichier, ligne)) {
            std::cout << "Ligne lue: " << ligne << std::endl;
        }
        mon_fichier.close();
    } else 
        std::cerr << "Impossible d'ouvrir le fichier \"" << nomfichier << "\"" << std::endl;
    return 0;
}