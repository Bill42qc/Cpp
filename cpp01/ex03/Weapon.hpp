 #pragma once


#include <iostream>


class Weapon
{
    public:
        Weapon(std::string 	newType);
        ~Weapon();
        const std::string &getType();
        void  setType(std::string newtype);

    private:
        std::string _type;
};