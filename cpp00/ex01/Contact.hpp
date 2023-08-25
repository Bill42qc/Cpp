#pragma once

#include <iostream>


//les infos ne peuvent pas etre vide !!!!
class Contact
{
public:
        Contact();
        Contact (std::string first_name,std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
        ~Contact ();
        std::string get_first_name ();
        std::string get_last_name ();
        std::string get_nickname ();
        std::string get_phone_number ();
        std::string get_darkest_secret ();
private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};