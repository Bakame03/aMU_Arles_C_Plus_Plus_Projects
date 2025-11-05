#include "iostream" 
#include "string"

int main(){
 std::cout << "Quel est votre nom ? >";
 std::string nom;
 std::cin >> nom;
 std::cout << "Quel est votre age ? >";
 unsigned int age;
 std::cin >> age;
 if(age >= 18){
  std::cout << nom << ", tu es majeur(e)." << std::endl;
 }else{
   std::cout << nom << ", tu es mineur(e)." << std::endl;
  }
 return 0;
};

