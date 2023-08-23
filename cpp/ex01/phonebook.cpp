#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
    index = 0;
}

PhoneBook::~PhoneBook(){}

std::string     ft_trunc(std::string str)
{
    std::string trunc;

    if(str.length() < 11)
        return (str);
    trunc = str;
    trunc[9] = '.';
    trunc[10] = '\0';
    return(trunc);
}

void PhoneBook::print()
{
    for(int i=0; i < 8; i++)
        {
            std::cout << std::setw(10) << i+1;
            std::cout << "|";
            std::cout << std::setw(10) << ft_trunc(array[i].get_first_name()); 
            std::cout << "|";
            std::cout << std::setw(10) << ft_trunc(array[i].get_last_name()); 
            std::cout << "|";
            std::cout << std::setw(10) << ft_trunc(array[i].get_nickname()); 
            std::cout << "|";
            std::cout << std::endl;
        }
}

void PhoneBook::search()
{
    std::string search_index;
    int         int_index;

    std::cout << "Enter contact index number to show :";
    std::getline(std::cin, search_index);
    if(std::cin.fail())
        return;
    if(search_index.length() == 1 && isnumber(search_index[0]))
    {
        int_index = stoi(search_index);
        if(int_index > 0 && int_index < 9)
        {
        std::cout << "First Name: " << array[int_index - 1].get_first_name() << std::endl;
        std::cout << "Last Name: " << array[int_index - 1].get_last_name() << std::endl;
        std::cout << "Nickname: " << array[int_index - 1].get_nickname() << std::endl;
        std::cout << "Phone Number: " << array[int_index - 1].get_phone_number() << std::endl;
        std::cout << "Darkest Secret: " << array[int_index - 1].get_darkest_secret()<< std::endl;
        }
        else
         std::cout << "Choose a valid index 🤡" << std::endl;
    }
    else
         std::cout << "Valid index only 🤡" << std::endl;
}