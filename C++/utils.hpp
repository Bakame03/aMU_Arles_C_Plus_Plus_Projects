#ifndef __UTILS__
#define __UTILS__
#include <vector>
#include <string>

struct Point {
    double x;
    double y;
};

struct Cercle{
    Point p;
    double r;
};

void ordonne3(double * a, double * b, double * c);
void echange2(double * a, double * b);
void reverseOrdreCaractere(char* str, int length);
void reverseCoordonnerPoint(Point &p);
void pointInterieurCercle(const Point& a, const Cercle& c);
void getDistanceEuclidienne(const Point& a, const Point& b, double &distanceEuclidienne);

void getmoyenne(const std::vector<double>& notes, const std::vector<double>& coefficients, float &moyenne);
void readDoubleVector(std::string sms, std::vector<double>& vec, int taille, int intervalle1, int intervalle2);
void readDouble(std::string, int intervalle1, int intervalle2, double &n);
void palindrome(std::string mot);
void removeZeros(std::vector<int>& tab);
void deleteFirstElement(std::vector<int>& tab, int &firstElement);
void deleteLastElement(std::vector<int>& tab, int &lastElement);
void getMoyenneElementsTableau(const std::vector<int>& tab, float &moyenne);
int getSommeElementsTableau(const std::vector<int>& tab, int &somme);
void afficheElementsTableau(const std::vector<int>& tab);
void valideYearMonthDay(int year, int month, int day);
void anneBissextile(int year);
void getNombreCaracteres(std::string s, int &nbreCaracteres);
void afficheNombrePairsDe1aN(int n);
void verifyAge(int jourNaissance, int moisNaissance, int anneeNaissance, int jourActuel, int moisActuel, int anneeActuel);
void verifyAge(int age);
void verifyNbreEntreIntervalle(int n, int n1, int n2);
void saisirIntrvalles(std::string msg, int &n1, int &n2);
void verifyPositiveNegativeNull(int n);
namespace trigonometrie {
    void conversionDegreToRadian(float degre, float &radian);
    void conversionRadianToDegre(float radian, float &degre);
}
namespace conversionMoney {
    void conversionUSDToEUR(float usd, float &eur);
    void conversionEURToUSD(float eur, float &usd);
}
void affiche(std::string msg, int n, std::string msg2, int m, std::string msg3, int o);
void affiche(std::string msg, int n, std::string msg2, int m);
void affiche(std::string msg, float n, std::string msg2, float m);
void affiche(std::string msg, float n);
void swap(int &a, int &b);
void swap(int &a, int &b, int &c);
void saisir(std::string msg, std::string &s);
void saisir(std::string msg, int &n);
void saisir(std::string msg, float &n);

#endif