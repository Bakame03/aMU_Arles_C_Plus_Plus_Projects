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
};

#endif 
