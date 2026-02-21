#include <iostream>
#include <string>
#include "Polynome.hpp"

int main() {
    const int TAILLE = 10;
    Polynome* tab[TAILLE] = {nullptr};
    int choix;

    do {
        afficher_etat(tab, TAILLE);
        std::cout << "Que voulez-vous faire ?\n";
        std::cout << "1. Creer / Ecraser un polynome dans un emplacement\n";
        std::cout << "2. Additionner deux polynomes (Z = X + Y)\n";
        std::cout << "3. Ajouter a un polynome (X += Y)\n";
        std::cout << "4. Soustraire deux polynomes (Z = X - Y)\n";
        std::cout << "5. Soustraire d'un polynome (X -= Y)\n";
        std::cout << "6. Deriver un polynome (Z = X.deriver())\n";
        std::cout << "7. Tester l'egalite de deux polynomes (X == Y)\n";
        std::cout << "8. Evaluer un polynome pour un reel donne ( y = P(x) )\n";
        std::cout << "9. Vider un emplacement\n";
        std::cout << "0. Quitter\n";
        std::cout << "Votre choix : ";
        std::cin >> choix;

        std::cout << std::endl;

        switch (choix) {
            case 1: {
                int index = demander_emplacement("Emplacement de destination");
                unsigned int degre;
                std::cout << "Entrez le degre du polynome : ";
                std::cin >> degre;
                
                double* coefs = new double[degre + 1];
                for (unsigned int i = 0; i <= degre; ++i) {
                    std::cout << "Coefficient pour x^" << i << " : ";
                    std::cin >> coefs[i];
                }
                
                // Si l'emplacement contient deja un polynome, on le supprime (evite les fuites de memoire)
                if (tab[index] != nullptr) {
                    delete tab[index]; 
                }
                
                // Creation du polynome en utilisant le constructeur
                tab[index] = new Polynome(degre, coefs);
                delete[] coefs; // Le constructeur fait sa propre copie des coefficients
                
                std::cout << "Polynome cree avec succes ! \n";
                break;
            }
            case 2: {
                int id1 = demander_emplacement("Emplacement du 1er polynome (X)");
                int id2 = demander_emplacement("Emplacement du 2e polynome (Y)");
                int dest = demander_emplacement("Emplacement de destination (Z)");
                
                if (tab[id1] != nullptr && tab[id2] != nullptr) {
                    if (tab[dest] != nullptr) delete tab[dest];
                    // Utilisation de l'operateur + declare dans la classe
                    tab[dest] = new Polynome(*tab[id1] + *tab[id2]);
                } else {
                    std::cout << "Erreur: les emplacements sources doivent contenir un polynome.\n";
                }
                break;
            }
            case 3: {
                int idDest = demander_emplacement("Emplacement a modifier (X)");
                int idSrc = demander_emplacement("Emplacement a ajouter (Y)");
                
                if (tab[idDest] != nullptr && tab[idSrc] != nullptr) {
                    // Utilisation de l'operateur +=
                    *tab[idDest] += *tab[idSrc];
                } else {
                    std::cout << "Erreur: les emplacements doivent contenir un polynome.\n";
                }
                break;
            }
            case 4: {
                int id1 = demander_emplacement("Emplacement du 1er polynome (X)");
                int id2 = demander_emplacement("Emplacement a soustraire (Y)");
                int dest = demander_emplacement("Emplacement de destination (Z)");
                
                if (tab[id1] != nullptr && tab[id2] != nullptr) {
                    if (tab[dest] != nullptr) delete tab[dest];
                    // Utilisation de l'operateur - 
                    tab[dest] = new Polynome(*tab[id1] - *tab[id2]);
                } else {
                    std::cout << "Erreur: les emplacements sources doivent contenir un polynome.\n";
                }
                break;
            }
            case 5: {
                int idDest = demander_emplacement("Emplacement a modifier (X)");
                int idSrc = demander_emplacement("Emplacement a soustraire (Y)");
                
                if (tab[idDest] != nullptr && tab[idSrc] != nullptr) {
                    // Utilisation de l'operateur -=
                    *tab[idDest] -= *tab[idSrc];
                } else {
                    std::cout << "Erreur: les emplacements doivent contenir un polynome.\n";
                }
                break;
            }
            case 6: {
                int idSrc = demander_emplacement("Emplacement du polynome a deriver");
                int dest = demander_emplacement("Emplacement de destination du resultat");
                
                if (tab[idSrc] != nullptr) {
                    if (tab[dest] != nullptr) delete tab[dest];
                    // Utilisation de la methode deriver()
                    tab[dest] = new Polynome(tab[idSrc]->deriver());
                } else {
                    std::cout << "Erreur: l'emplacement source doit contenir un polynome.\n";
                }
                break;
            }
            case 7: {
                int id1 = demander_emplacement("Emplacement du 1er polynome");
                int id2 = demander_emplacement("Emplacement du 2e polynome");
                
                if (tab[id1] != nullptr && tab[id2] != nullptr) {
                    // Utilisation de l'operateur ==
                    if (*tab[id1] == *tab[id2]) {
                        std::cout << "-> Les deux polynomes sont EGAUX.\n";
                    } else {
                        std::cout << "-> Les deux polynomes sont DIFFERENTS.\n";
                    }
                } else {
                    std::cout << "Erreur: emplacements vides.\n";
                }
                break;
            }
            case 8: {
                int index = demander_emplacement("Emplacement du polynome");
                if (tab[index] != nullptr) {
                    double x;
                    std::cout << "Entrez la valeur de (x) : ";
                    std::cin >> x;
                    // Utilisation de l'operateur ()
                    std::cout << "Resultat: P(" << x << ") = " << (*tab[index])(x) << "\n";
                } else {
                    std::cout << "Erreur: l'emplacement doit contenir un polynome.\n";
                }
                break;
            }
            case 9: {
                int index = demander_emplacement("Emplacement a vider");
                if (tab[index] != nullptr) {
                    delete tab[index];
                    tab[index] = nullptr;
                    std::cout << "Emplacement " << index << " a ete vide avec succes.\n";
                } else {
                    std::cout << "L'emplacement est deja vide.\n";
                }
                break;
            }
            case 0:
                std::cout << "Fermeture du programme...\n";
                break;
            default:
                std::cout << "Choix invalide. Reessayez.\n";
        }
    } while (choix != 0);

    // Liberation de toute la memoire (nettoyage) a la fin du programme
    for (int i = 0; i < TAILLE; ++i) {
        if (tab[i] != nullptr) {
            delete tab[i];
            tab[i] = nullptr;
        }
    }

    return 0;
}
