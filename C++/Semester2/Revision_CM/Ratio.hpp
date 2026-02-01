#ifndef __RATIO_HPP__
#define __RATIO_HPP__

class Ratio{
    private:
        int num;
        unsigned int den;
    public:
        Ratio(int numerator = 0, unsigned int denominator = 1);
        void affecter(int numerator, unsigned int denominator);
        void afficher(std::ostream& os) const; 
        double valeurReelle() const;
        ~Ratio();
};

#endif 