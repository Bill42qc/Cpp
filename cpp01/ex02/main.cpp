#include <iostream>


int main ()
{
   std::string str = "HI THIS IS BRAIN";
   std::string *stringPTR = &str;
   std::string &stringREF = str;


   std::cout << "ADRESSE de la string en memoire" << std::endl;
   std::cout << &str << std::endl;
   std::cout << "ADRESSE de stringPTR" << std::endl;
   std::cout << stringPTR << std::endl;
   std::cout << "ADRESSE de stringREF" << std::endl;
   std::cout << &stringREF << std::endl;

   std::cout << "VALEUR de la string en memoire" << std::endl;
   std::cout << str << std::endl;
   std::cout << "VALEUR de stringPTR" << std::endl;
   std::cout << *stringPTR << std::endl;
   std::cout << "VALEUR de stringREF" << std::endl;
   std::cout << stringREF << std::endl;
}