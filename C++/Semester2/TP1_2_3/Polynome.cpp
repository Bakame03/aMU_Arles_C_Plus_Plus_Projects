#include <iostream>
#include "Polynome.hpp"

Polynome::Polynome(unsigned int _degre, double _coef[])
    : degre(_degre), coef(nullptr) {
    coef = new double[degre + 1];
    for (unsigned int i = 0; i <= degre; ++i) 
        coef[i] = _coef[i];
}

Polynome::~Polynome() {
    delete[] coef;
}

// Original copy constructor implementation (From sctratch)
// Polynome::Polynome(const Polynome& p)
//     : degre(p.degre), coef(nullptr) {
//     coef = new double[degre + 1];
//     for (unsigned int i = 0; i <= degre; ++i) 
//         coef[i] = p.coef[i];
// }

// Using delegating constructor to avoid code duplication
Polynome::Polynome(const Polynome& p)
    : Polynome(p.degre, p.coef) {
}

Polynome& Polynome::operator+=(const Polynome& p) {
    if (p.degre > degre) {
        double* newCoef = new double[p.degre + 1];
        for (unsigned int i = 0; i <= degre; i++)
            newCoef[i] = coef[i] + p.coef[i];
        for (unsigned int i = degre + 1; i <= p.degre; i++)
            newCoef[i] = p.coef[i];
        delete[] coef;
        coef = newCoef;
        degre = p.degre;
    } else {
        for (unsigned int i = 0; i <= p.degre; i++)
            coef[i] += p.coef[i];
    }
    return *this;
}

Polynome& Polynome::operator-=(const Polynome& p) {
    if (p.degre > degre) {
        double* newCoef = new double[p.degre + 1];
        for (unsigned int i = 0; i <= degre; i++)
            newCoef[i] = coef[i] - p.coef[i];
        for (unsigned int i = degre + 1; i <= p.degre; i++)
            newCoef[i] = -p.coef[i];
        delete[] coef;
        coef = newCoef;
        degre = p.degre;
    } else {
        for (unsigned int i = 0; i <= p.degre; i++)
            coef[i] -= p.coef[i];
    }
    return *this;
}

Polynome Polynome::deriver() const {
    if (degre == 0) {
        double zeroCoef[1] = {0.0};
        return Polynome(0, zeroCoef);
    }
    double* newCoef = new double[degre];
    for (unsigned int i = 1; i <= degre; i++) {
        newCoef[i - 1] = coef[i] * i;
    }
    Polynome derivedPoly(degre - 1, newCoef);
    delete[] newCoef;
    return derivedPoly;
}