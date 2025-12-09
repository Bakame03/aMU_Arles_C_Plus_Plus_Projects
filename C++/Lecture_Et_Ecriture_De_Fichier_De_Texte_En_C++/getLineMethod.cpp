#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure pour représenter une date
struct Date {
    int day, month, year;
};

// Structure pour représenter une personne (Formulaire)
struct Form {
    string lastname;
    string firstname;
    int age;
    double size;
    bool female;
    Date birth;
    Date death;
};

// Fonction pour lire une date (Exercice : implémentation basique ajoutée pour que ça compile)
istream& read_date(istream& is, Date& d) {
    char slash; // Pour lire les '/' entre les nombres
    is >> d.day >> slash >> d.month >> slash >> d.year;
    return is;
}

// Lire les valeurs de f depuis is. Remarquez les passages de paramètres par référence !
istream& read_form(istream& is, Form& f) {
    // Mettre tout le contenu de la première ligne dans le nom de f.
    // Note: ws permet d'ignorer les espaces blancs initiaux s'il y en a.
    getline(is >> ws, f.lastname); 
    
    // Idem avec le prénom de f.
    getline(is >> ws, f.firstname);
    
    // Lire l’age et la taille.
    is >> f.age >> f.size;
    
    // Lire un caractère qui sera soit F (female) soit M (male).
    char s = 'X'; 
    is >> s; 
    
    // La personne est une femme si la lettre est ’F’.
    f.female = (s == 'F'); 
    
    // Lire la date de naissance
    read_date(is, f.birth); 
    
    // et la date de décès.
    read_date(is, f.death); 
    
    return is;
}

int main() {
    // Associe le nom du fichier à la variable de flux
    ifstream file("AlanTuring.txt"); 
    
    // On crée une variable non-initialisée
    Form aturing; 
    
    // Vérifier si le fichier est ouvert avant de lire
    if (!file) {
        cerr << "Erreur: Impossible d'ouvrir le fichier AlanTuring.txt" << endl;
        return 1;
    }

    // On lit à partir de « flux » vers « aturing ».
    read_form(file, aturing); 
    
    // Si file est équivalent à true alors c’est que toutes les lectures ont réussi.
    if (file) { 
        // Utiliser la fiche désormais initialisée avec les données d’Alan Turing.
        cout << "Lecture reussie !" << endl;
        cout << "Nom: " << aturing.lastname << endl;
        cout << "Prenom: " << aturing.firstname << endl;
        cout << "Age: " << aturing.age << " ans" << endl;
        cout << "Taille: " << aturing.size << " m" << endl;
        cout << "Sexe: " << (aturing.female ? "Femme" : "Homme") << endl;
        cout << "Date de naissance: " << aturing.birth.day << "/" << aturing.birth.month << "/"
             << aturing.birth.year << endl;
        cout << "Date de deces: " << aturing.death.day << "/" << aturing.death.month << "/"
             << aturing.death.year << endl;
    } else {
        cerr << "Erreur lors de la lecture du fichier." << endl;
    }
    
    return 0;
}