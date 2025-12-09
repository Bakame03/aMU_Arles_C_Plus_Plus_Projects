#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream monfichier("file_test.txt");
    std::vector<double> tableau;
    double valeur;
    while(monfichier >> valeur) 
        tableau.push_back(valeur);
    std::cout << "Il y a " << tableau.size() << " valeurs dans le tableau." << std::endl;
    return 0;
}