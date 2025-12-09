#include <iostream>
#include <fstream>

int main() {
    std::ofstream mon_fichier("file_test.txt");
    if (mon_fichier.is_open())
        mon_fichier << "Cette phrase est ecrite dans le fichier." << std::endl;
    else
        std::cerr << "Impossible d'ouvrir le fichier en ecriture." << std::endl;
    return 0;
}