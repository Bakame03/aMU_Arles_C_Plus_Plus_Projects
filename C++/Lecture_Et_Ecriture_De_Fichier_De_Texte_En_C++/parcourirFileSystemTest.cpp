#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem; // Raccourci pour simplifier l’écriture de l’espace de nom

int main() {
    // On récupère le chemin du répertoire courant (là où l'exécutable est lancé).
    fs::path rep_courant = fs::current_path(); 
    
    // On prépare un "itérateur" pour parcourir le dossier.
    // C'est comme une liste qui pointe vers le contenu du dossier.
    fs::directory_iterator di(rep_courant); 
    
    // Boucle "for-each" : Pour chaque élément (entrée) dans le dossier...
    for (const fs::directory_entry& de : di) {
        
        // On récupère le chemin complet de l'élément actuel
        fs::path dep = de.path(); 
        
        // On affiche juste le nom du fichier (pas tout le chemin /home/user/...)
        cout << dep.filename(); 
        
        // Test : Est-ce un fichier normal (texte, image, exécutable...) ?
        if (de.is_regular_file()) {
            cout << " est un fichier standard de "
                 << de.file_size() << " octets." << endl;
        }
        // Test : Est-ce un dossier ?
        else if (de.is_directory()) {
            cout << " est un sous-repertoire." << endl;
        }
        // Sinon (lien symbolique, socket, périphérique...)
        else {
            cout << " n'est ni un fichier classique ni un repertoire." << endl;
        }
    }
    
    return EXIT_SUCCESS;
}