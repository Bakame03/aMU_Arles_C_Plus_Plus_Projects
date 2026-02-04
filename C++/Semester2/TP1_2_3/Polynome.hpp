#ifndef __POLYNOME_HPP__
#define __POLYNOME_HPP__

class Polynome {
private:
    unsigned int degre;
    double* coef;
public:
    Polynome(unsigned int _degre, double _coef[]);
    Polynome(const Polynome& p);
    Polynome() = delete;
    inline unsigned int getDegre() const { return degre; }
    ~Polynome();
    Polynome& operator+=(const Polynome& p);
    Polynome& operator-=(const Polynome& p);
    Polynome deriver() const;
    Polynome& operator=(const Polynome& p);
    inline unsigned int getDegre() const { return degre; }
    friend bool operator==(const Polynome& p1, const Polynome& p2);
    friend Polynome operator+(const Polynome& p1, const Polynome& p2);
};

// - implement operator -
// - implement operator *
// - implement operator / (qui donne le polynome quotient)
// - implement operator % (qui donne le polynome reste)

#endif 
