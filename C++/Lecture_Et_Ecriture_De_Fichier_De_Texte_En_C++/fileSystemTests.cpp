#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem; // Raccourci pour simplifier l’écriture de l’espace de nom

int main() {
    // On récupère le chemin du répertoire courant.
    fs::path rep_courant = fs::current_path(); 
    
    // On définit le chemin du nouveau dossier
    fs::path nouveau_rep = rep_courant / "NouveauRep2";
    
    // On crée le répertoire "NouveauRep" dans le répertoire courant.
    // create_directory renvoie true si le dossier a été créé, false s'il existait déjà.
    if (fs::create_directory(nouveau_rep)) {
        cout << "Dossier 'NouveauRep' cree avec succes." << endl;
    } else {
        cout << "Le dossier existe peut-etre deja." << endl;
    }

    // On définit le chemin du fichier à l'intérieur du dossier
    fs::path chemin_fichier = nouveau_rep / "MonFichier.txt";
    
    // On crée "MonFichier.txt" dans "NouveauRep"
    ofstream ofs(chemin_fichier); 
    
    // Vérification que le fichier est bien ouvert
    if (ofs) {
        ofs << "Ce texte sera écrit dans le fichier." << endl; // et on écrit dedans.
        ofs.close(); // Bonne pratique : fermer le fichier explicitement (même si le destructeur le fait)
    } else {
        cerr << "Erreur: Impossible de creer le fichier." << endl;
        return 1;
    }

    // Affichage du nom du fichier seul
    cout << "On a ecrit dans le fichier " << chemin_fichier.filename() << endl;

    // Affichage du nom du fichier seul sans extension
    cout << "On a ecrit dans le fichier " << chemin_fichier.stem() << endl;

    // Affichage du nom de l'extension seule
    cout << "L'extension du fichier est " << chemin_fichier.extension() << endl;

    // Affichage du nom du repertoire parent
    cout << "Le repertoire parent est " << chemin_fichier.parent_path() << endl;
    
    // Conversion explicite de fs::path à string pour affichage
    string cfc = chemin_fichier.string(); 
    
    cout << "Le chemin sous forme de chaine est " << cfc << endl;
    
    return EXIT_SUCCESS;
}