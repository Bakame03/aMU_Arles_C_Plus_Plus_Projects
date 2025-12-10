#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

static std::size_t utf8_strlen(const std::string &s) {
    std::size_t count = 0;
    for (size_t i = 0; i < s.length(); ) {
        unsigned char c = s[i];
        
        if ((c & 0xC0) != 0x80) {
            if (!std::isspace(c) && c != '\'' && c != '-') {
                count++;
            }
            
            if ((c & 0x80) == 0) {
                i += 1;
            } else if ((c & 0xE0) == 0xC0) {
                i += 2;
            } else if ((c & 0xF0) == 0xE0) {
                i += 3;
            } else if ((c & 0xF8) == 0xF0) {
                i += 4;
            } else {
                i += 1;
            }
        } else {
            i++;
        }
    }
    return count;
}

int main() {
    std::string nomfichier = "liste_de_mots_francais-UTF8-LF.txt";
    std::ifstream mon_fichier(nomfichier);
    if (!mon_fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier \"" << nomfichier << "\"" << std::endl;
        return 1;
    }

    std::string mot;
    int ligne = 0;
    
    std::cout << "Recherche des mots avec 22 lettres...\n" << std::endl;
    
    while (std::getline(mon_fichier, mot)) {
        ligne++;
        size_t len = utf8_strlen(mot);
        
        if (len == 22) {
            std::cout << "Ligne " << ligne << ": \"" << mot << "\" -> " << len << " lettres" << std::endl;
        }
    }
    
    mon_fichier.close();
    std::cout << "\nTotal de lignes lues: " << ligne << std::endl;
    
    return 0;
}
