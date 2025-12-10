#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::string nomfichier = "liste_de_mots_francais-UTF8-LF.txt";
    std::ifstream mon_fichier(nomfichier);
    if (!mon_fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier \"" << nomfichier << "\"" << std::endl;
        return 1;
    }

    std::vector<std::string> motsFrancais;
    std::string mot;
    while (std::getline(mon_fichier, mot)) {
        motsFrancais.push_back(mot);
    }
    mon_fichier.close();

    int nombreDeLettres;
    do {
        std::cout << "Entrez un nombre de lettres (entre 1 et 22) ou 0 pour quitter : ";
        std::cin >> nombreDeLettres;

        if (nombreDeLettres < 0 || nombreDeLettres > 22) {
            std::cout << "Nombre invalide. Veuillez réessayer." << std::endl;
        } else if (nombreDeLettres != 0) {
            int compteur = 0;
            for (const auto& mot : motsFrancais) {
                // Count UTF-8 characters (letters only, skip spaces and punctuation)
                std::size_t count = 0;
                for (unsigned char c : mot) {
                    if (!std::isspace(c) && c != '\'' && c != '-') {
                        if ((c & 0xC0) != 0x80) {  // Leading byte, not continuation
                            count++;
                        }
                    }
                }
                if (count == static_cast<size_t>(nombreDeLettres)) {
                    compteur++;
                }
            }
            std::cout << "Il y a " << compteur << " mots avec " << nombreDeLettres << " lettres." << std::endl;
        }
    } while (nombreDeLettres != 0);

    return 0;
}