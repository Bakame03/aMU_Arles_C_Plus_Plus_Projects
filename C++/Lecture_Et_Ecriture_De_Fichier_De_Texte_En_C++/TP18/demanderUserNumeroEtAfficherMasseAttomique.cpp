#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::string nomfichier = "MasseAtomiqueParElement.txt";
    std::ifstream mon_fichier(nomfichier);
    if (!mon_fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier \"" << nomfichier << "\"" << std::endl;
        return 1;
    }

    std::vector<double> masses_atomiques;
    double masse;
    while (mon_fichier >> masse) {
        masses_atomiques.push_back(masse);
    }
    mon_fichier.close();

    int numero_atomique;
    do {
        std::cout << "Entrez un numéro atomique (0 pour quitter) : ";
        std::cin >> numero_atomique;

        if (numero_atomique < 0 || numero_atomique > static_cast<int>(masses_atomiques.size())) {
            std::cout << "Numéro atomique invalide. Veuillez réessayer." << std::endl;
        } else if (numero_atomique != 0) {
            std::cout << "Masse atomique de l'élément " << numero_atomique << " : "
                      << masses_atomiques[numero_atomique - 1] << std::endl;
        }
    } while (numero_atomique != 0);

    return 0;
}