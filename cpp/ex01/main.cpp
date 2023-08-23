#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void ft_add(PhoneBook& phonebook)
{
    std::string first, last, nick, phone, secret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, first);
    if(std::cin.fail() || first == "")
    {
        std::cout << "Empty Field = Reset contact import 🤡" << std::endl;
        return;
    }
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last);
    if(std::cin.fail() || last == "")
    {
        std::cout << "Empty Field = Reset contact import 🤡" << std::endl;
        return;
    }
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nick);
    if(std::cin.fail() || nick == "")
    {
        std::cout << "Empty Field = Reset contact import 🤡" << std::endl;
        return;
    }
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone);
    if(std::cin.fail() || phone == "")
    {
        std::cout << "Empty Field = Reset contact import 🤡" << std::endl;
        return;
    }
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, secret);
    if(std::cin.fail() || secret == "")
    {
        std::cout << "Empty Field = Reset contact import 🤡" << std::endl;
        return;
    }
    phonebook.array[phonebook.index] = Contact(first,last,nick,phone,secret);
    phonebook.index++;
    if(phonebook.index > 7)
    phonebook.index = 0;
}


int main ()
{
std::string str;
PhoneBook phonebook;

while(true)
{
    std::cout << "Enter ADD || SEARCH || EXIT : "; 
    std::getline(std::cin, str);
    if(std::cin.fail())
        return(1);
    
    if(str == "ADD")
        ft_add(phonebook);
    
   else if(str == "SEARCH")
   {
        phonebook.print();
        phonebook.search();
   }
    else if(str == "EXIT")
        return(0);
}   
}