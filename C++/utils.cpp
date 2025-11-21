#include <iostream>
#include <string>
#include "utils.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

void afficheListeIntTableauCroissantWithoutOccurencesUsingSTD_SORT(const std::vector<int>& tab) {
    std::vector<int> sortedTab = tab; 
    std::sort(sortedTab.begin(), sortedTab.end());
    std::cout << "Elements du tableau en ordre croissant sans occurrences (utilisant std::sort) :" << std::endl;
    if (!sortedTab.empty()) {
        std::cout << sortedTab[0] << " ";
        for (size_t i = 1; i < sortedTab.size(); ++i) {
            if (sortedTab[i] != sortedTab[i - 1]) {
                std::cout << sortedTab[i] << " ";
            }
        }
    }
    std::cout << std::endl;
}

void afficheListeIntTableauCroissantWithoutOccurences(const std::vector<int>& tab) {
    std::vector<int> sortedTab = tab; 
    for (size_t i = 0; i < sortedTab.size(); ++i) {
        for (size_t j = i + 1; j < sortedTab.size(); ++j) {
            if (sortedTab[i] > sortedTab[j]) {
                int temp = sortedTab[i];
                sortedTab[i] = sortedTab[j];
                sortedTab[j] = temp;
            }
        }
    }
    std::cout << "Elements du tableau en ordre croissant sans occurrences :" << std::endl;
    if (!sortedTab.empty()) {
        std::cout << sortedTab[0] << " ";
        for (size_t i = 1; i < sortedTab.size(); ++i) {
            if (sortedTab[i] != sortedTab[i - 1]) {
                std::cout << sortedTab[i] << " ";
            }
        }
    }
    std::cout << std::endl;
}

void afficheListeIntTableauCroissant(const std::vector<int>& tab) {
    std::vector<int> sortedTab = tab; 
    for (size_t i = 0; i < sortedTab.size(); ++i) {
        for (size_t j = i + 1; j < sortedTab.size(); ++j) {
            if (sortedTab[i] > sortedTab[j]) {
                int temp = sortedTab[i];
                sortedTab[i] = sortedTab[j];
                sortedTab[j] = temp;
            }
        }
    }
    std::cout << "Elements du tableau en ordre croissant :" << std::endl;
    for (int value : sortedTab) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void afficheListeIntTableau(const std::vector<int>& tab){
    std::cout << "Elements du tableau :" << std::endl;
    for (int value : tab) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void getListeInt(std::vector<int>& listeInt) {
    std::string valeur;
    int n;
    do
    {
        std::cout << "Entrez un entier : ";
        std::getline(std::cin, valeur);
        if (valeur.empty()) {
            n = 0;
        } else {
            n = std::stoi(valeur);
        }
        listeInt.push_back(n);
    } while (valeur.empty() == false);
}

void echange2(double * a, double * b) {
    if(*a > *b) {
        double temp = *a;
        *a = *b;
        *b = temp;
    }
}

void ordonne3(double * a, double * b, double * c) {
    echange2(a, b);
    echange2(a, c);
    echange2(b, c);
}


void reverseOrdreCaractere(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseCoordonnerPoint(Point &p) {
    double temp = p.x;
    p.x = p.y;
    p.y = temp;
}

void pointInterieurCercle(const Point& a, const Cercle& c) {
    double distance;
    getDistanceEuclidienne(a, c.p, distance);
    if (distance < c.r) {
        std::cout << "Le point est a l'interieur du cercle." << std::endl;
    } else if (distance == c.r) {
        std::cout << "Le point est sur le cercle." << std::endl;
    } else {
        std::cout << "Le point est a l'exterieur du cercle." << std::endl;
    }
}

void getDistanceEuclidienne(const Point& a, const Point& b, double &distanceEuclidienne) {
    double deltaX = b.x - a.x;
    double deltaY = b.y - a.y;
    distanceEuclidienne = std::sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

void getmoyenne(const std::vector<double>& notes, const std::vector<double>& coefficients, float &moyenne) {
    if (notes.size() != coefficients.size() || notes.empty()) {
        moyenne = 0.0f;
        std::cout << "Erreur : Les vecteurs de notes et de coefficients doivent avoir la meme taille et ne pas etre vides." << std::endl;
        return;
    }
    double sommePonderee = 0.0;
    double sommeCoefficients = 0.0;
    for (size_t i = 0; i < notes.size(); ++i) {
        sommePonderee += notes[i] * coefficients[i];
        sommeCoefficients += coefficients[i];
    }
    if (sommeCoefficients == 0) {
        moyenne = 0.0f;
        std::cout << "Erreur : La somme des coefficients est nulle." << std::endl;
        return;
    }
    moyenne = static_cast<float>(sommePonderee / sommeCoefficients);
}

void readDoubleVector(std::string sms, std::vector<double>& vec, int taille, int intervalle1, int intervalle2) {
    for (int i = 0; i < taille; ++i) {
        double n;
        readDouble(sms, intervalle1, intervalle2, n);
        vec.push_back(n);
    }
}

void readDouble(std::string sms, int intervalle1, int intervalle2, double &n) {
    std::cout << sms << intervalle1 << " et " << intervalle2 << " : ";
    std::cin >> n;
    while (n < intervalle1 || n > intervalle2) {
        std::cout << "Nombre invalide. Veuillez saisir un nombre a virgule entre " << intervalle1 << " et " << intervalle2 << " : ";
        std::cin >> n;
    }
}

void palindrome(std::string mot) {
    std::string motInverse = "";
    for (int i = mot.length() - 1; i >= 0; --i) {
        motInverse += mot[i];
    }
    if (mot == motInverse) {
        std::cout << "Le mot \"" << mot << "\" est un palindrome." << std::endl;
    } else {
        std::cout << "Le mot \"" << mot << "\" n'est pas un palindrome." << std::endl;
    }
}

void removeZeros(std::vector<int>& tab) {
    size_t writeIndex = 0;
    for (size_t readIndex = 0; readIndex < tab.size(); ++readIndex) {
        if (tab[readIndex] != 0) {
            tab[writeIndex] = tab[readIndex];
            writeIndex++;
        }
    }
    tab.resize(writeIndex);
}

void deleteFirstElement(std::vector<int>& tab, int &firstElement) {
    if (tab.empty()) {
        std::cout << "Le tableau est vide. Aucun element a supprimer." << std::endl;
        return;
    }
    firstElement = tab.front();
    for(size_t i = 0; (i < tab.size() - 1); ++i) {
        tab[i] = tab[i + 1];
    }
    tab.pop_back();
    std::cout << "Premier element supprime : " << firstElement << std::endl;
}

void deleteLastElement(std::vector<int>& tab, int &lastElement) {
    if (tab.empty()) {
        std::cout << "Le tableau est vide. Aucun element a supprimer." << std::endl;
        return;
    }
    lastElement = tab.back();
    tab.pop_back();
    std::cout << "Dernier element supprime : " << lastElement << std::endl;
}

void getMoyenneElementsTableau(const std::vector<int>& tab, float &moyenne) {
    if (tab.empty()) {
        moyenne = 0.0f;
        return;
    }
    int somme = 0;
    somme = getSommeElementsTableau(tab, somme);
    moyenne = static_cast<float>(somme) / tab.size();
    std::cout << "Moyenne des elements du tableau : " << moyenne << std::endl;
}

int getSommeElementsTableau(const std::vector<int>& tab, int &somme) {
    somme = 0;
    for (size_t i = 0; i < tab.size(); ++i) {
        somme += tab[i];
    }
    return somme;
}

void afficheElementsTableau(const std::vector<int>& tab) {
    std::cout << "Elements du tableau :" << std::endl;
    for (size_t i = 0; i < tab.size(); ++i) {
        std::cout << tab[i];
        if(i < tab.size() - 1) {
            std::cout << ", ";
        }else {
            std::cout << std::endl;
        }
    }
}

void valideYearMonthDay(int year, int month, int day) {
    bool isValid = true;

    if (year < 0) {
        std::cout << "L'annee saisie n'est pas valide." << std::endl;
        isValid = false;
    }

    if (month < 1 || month > 12) {
        std::cout << "Le mois saisi n'est pas valide." << std::endl;
        isValid = false;
    }

    if (day < 1 || day > 31) {
        std::cout << "Le jour saisi n'est pas valide." << std::endl;
        isValid = false;
    } else {
        // Verification des jours en fonction du mois
        if (month == 2) { // Fevrier
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (day > (isLeapYear ? 29 : 28)) {
                std::cout << "Le jour saisi n'est pas valide pour le mois de fevrier." << std::endl;
                isValid = false;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) { // Avril, Juin, Septembre, Novembre
            if (day > 30) {
                std::cout << "Le jour saisi n'est pas valide pour le mois de " 
                          << (month == 4 ? "avril." : month == 6 ? "juin." : month == 9 ? "septembre." : "novembre.") 
                          << std::endl;
                isValid = false;
            }
        }
    }

    if (isValid) {
        std::cout << "La date " << day << "/" << month << "/" << year << " est valide." << std::endl;
    } else {
        std::cout << "La date " << day << "/" << month << "/" << year << " n'est pas valide." << std::endl;
    }
}

void anneBissextile(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        std::cout << year << " est une annee bissextile." << std::endl;
    } else {
        std::cout << year << " n'est pas une annee bissextile." << std::endl;
    }
}

void getNombreCaracteres(std::string s, int &nbreCaracteres) {
    nbreCaracteres = 0;
    for (char c : s) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
            nbreCaracteres++;
        }
    }
}

void afficheNombrePairsDe1aN(int n) {
    std::cout << "Nombres pairs de 1 a " << n << " :" << std::endl;
    for (int i = 2; i <= n; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void verifyAge(int jourNaissance, int moisNaissance, int anneeNaissance, int jourActuel, int moisActuel, int anneeActuel) {
    int age = anneeActuel - anneeNaissance;
    if (moisActuel < moisNaissance || (moisActuel == moisNaissance && jourActuel < jourNaissance)) {
        age--;
    }
    verifyAge(age);
}

void verifyAge(int age) {
    if (age >= 18) {
        std::cout << "Vous etes majeur." << std::endl;
    } else {
        std::cout << "Vous etes mineur." << std::endl;
    }
}

void verifyNbreEntreIntervalle(int n, int n1, int n2) {
    if (n >= n1 && n <= n2) {
        std::cout << "Le nombre " << n << " est entre l'intervalle [" << n1 << ", " << n2 << "]." << std::endl;
    } else {
        std::cout << "Le nombre " << n << " n'est pas entre l'intervalle [" << n1 << ", " << n2 << "]." << std::endl;
    }
}

void saisirIntrvalles(std::string msg, int &n1, int &n2) {
    std::cout << msg;
    std::cout << "Veuillez saisir le premier intervalle: ";
    std::cin >> n1;
    std::cout << "Veuillez saisir le deuxieme intervalle: ";
    std::cin >> n2;
    while (n1 == n2) {
        std::cout << "Intervalle invalide. Veuillez saisir un intervalle valide (n1 < n2) : ";
        std::cin >> n1 >> n2;
    }
    while (n1 > n2)
    {
        swap(n1, n2);
        std::cout << "Les bornes ont ete permutees pour respecter l'ordre croissant." << std::endl;
    }
    
}

void verifyPositiveNegativeNull(int n) {
    if (n > 0) {
        std::cout << "Le nombre " << n << " est positif." << std::endl;
    } else if (n < 0) {
        std::cout << "Le nombre " << n << " est negatif." << std::endl;
    } else {
        std::cout << "Le nombre est nul." << std::endl;
    }
}

namespace trigonometrie {
    const float PI = 3.14159;

    void conversionDegreToRadian(float degre, float &radian) {
        radian = degre * (PI / 180.0);
    }

    void conversionRadianToDegre(float radian, float &degre) {
        degre = radian * (180.0 / PI);
    }
}

namespace conversionMoney {
    const float USD_TO_EUR = 0.695690891; 
    const float EUR_TO_USD = 1.43742; 

    void conversionUSDToEUR(float usd, float &eur) {
        eur = usd * USD_TO_EUR;
    }

    void conversionEURToUSD(float eur, float &usd) {
        usd = eur * EUR_TO_USD;
    }
}

void affiche(std::string msg, int n, std::string msg2, int m, std::string msg3, int o) {
    std::cout << msg << n << msg2 << m << msg3 << o << std::endl;
}

void affiche(std::string msg, int n, std::string msg2, int m) {
    std::cout << msg << n << msg2 << m << std::endl;
}

void affiche(std::string msg, float n, std::string msg2, float m) {
    std::cout << msg << n << msg2 << m << std::endl;
}

void affiche(std::string msg, float n) {
    std::cout << msg << n << std::endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

void saisir(std::string msg, std::string &s) {
    std::cout << msg;
    std::getline(std::cin, s);
}

void saisir(std::string msg, int &n) {
    std::cout << msg;
    std::cin >> n;
}

void saisir(std::string msg, float &n) {
    std::cout << msg;
    std::cin >> n;
}