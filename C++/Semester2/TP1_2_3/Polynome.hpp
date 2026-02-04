#ifndef __POLYNOME_HPP__
#define __POLYNOME_HPP__

class Polynome {
private:
    unsigned int degre;
    double* coef;
public:
    Polynome(unsigned int _degre, double _coef[]);
    ~Polynome();
    Polynome() = delete;
    Polynome(const Polynome& p);
    inline unsigned int getDegre() const { return degre; }
    Polynome& operator+=(const Polynome& p);
    Polynome& operator-=(const Polynome& p);
    Polynome deriver() const;
    Polynome& operator=(const Polynome& p);
    friend bool operator==(const Polynome& p1, const Polynome& p2);
    friend Polynome operator+(const Polynome& p1, const Polynome& p2);
    friend std::ostream& operator<<(std::ostream& os, const Polynome& p);
    inline const double& operator[](const int i) {
        if (i <= degre)
            return coef[i];
        else {
            throw std::out_of_range("Index out of range");
        }
    }
    double operator()(double x);
};

// To do:
// - implement integration method(integrale) that returns the indefinite integral of the polynomial
// - simplification de chaque polynome a chaque operatioin 
//      pouvant produire un polynôme dont les monômes de plus haut degré peuvent être nuls 
// - implement operator -
// - implement operator *
// - implement operator / (qui donne le polynome quotient)
// - implement operator % (qui donne le polynome reste)
// - enhance operator << to:
//     - ne pas afficher le '+' devant un monome si le coefficient est negatif
//     - ne pas afficher du tout les monomes dont le coefficient est nul 
//     - ne pas afficher le coefficient s'il vaut +1
//     - n'afficher que '-' a la place du coefficient lorsqu'il vaut -1
//     - ne pas afficher 'x^0' pour le monome constant 
//     - quand le polynome est constant (c'est a dire de degre 0), afficher seulement la constante
// - enhance operator () to use Horner's method for polynomial evaluation (without using std::pow)
#endif 
