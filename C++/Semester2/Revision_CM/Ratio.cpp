#include <iostream>
#include "Ratio.hpp"

Ratio::Ratio(int numerator = 0, unsigned int denominator = 1)
    :   num(numerator), den(denominator) {}

Ratio::~Ratio(){}

void Ratio::affecter(int numerator, unsigned int denominator){
    num = numerator;
    den = denominator;
}

void Ratio::afficher(std::ostream& os) const{
    os << num << "/" << den << std::endl;
}

double Ratio::valeurReelle() const{
    return double(num)/den;
}