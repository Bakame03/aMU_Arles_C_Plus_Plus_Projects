#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream monfichier("file_test.txt");
    std::vector<std::string> tableau;
    std::string content;
    while(std::getline(monfichier, content))
        tableau.push_back(content);
    std::cout << "Il y a " << tableau.size() << " lignes dans le tableau." << std::endl;
    return 0;
}