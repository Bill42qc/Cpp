#pragma once

#include <iostream>
#include "Contact.hpp"


class PhoneBook
{
public :
    PhoneBook();
    ~PhoneBook();
    void print();
    void search();
    Contact   array[8];
    int       index;

private:

};
