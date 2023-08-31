#include "Harl.hpp"
#include <map>

Harl::Harl()
{
}
Harl::~Harl() {}

void Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl
              << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger. "
                 "I really do !"
              << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]" << std::endl
              << "I cannot believe adding extra bacon costs more money."
                 "You didn’t put enough bacon in my burger ! If you did, I wouldn’t"
                 " be asking for more !"
              << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]" << std::endl
              << "I think I deserve to have some extra bacon for free. I’ve been coming"
                 "for years whereas you started working here since last month."
              << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]" << std::endl
              << "This is unacceptable ! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level)
{
    ComplaintFunction complaintFunctions[4];
    std::map<std::string, int> levelToIndex;

    levelToIndex["DEBUG"] = 0;
    levelToIndex["INFO"] = 1;
    levelToIndex["WARNING"] = 2;
    levelToIndex["ERROR"] = 3;

    complaintFunctions[0] = &Harl::debug;
    complaintFunctions[1] = &Harl::info;
    complaintFunctions[2] = &Harl::warning;
    complaintFunctions[3] = &Harl::error;

    std::map<std::string, int>::iterator i = levelToIndex.find(level);
    if (i != levelToIndex.end())
    {
        int index = i->second;

        switch (index)
        {
        case 0:
            (this->*complaintFunctions[0])();
        case 1:
            (this->*complaintFunctions[1])();
        case 2:
            (this->*complaintFunctions[2])();
        case 3:
            (this->*complaintFunctions[3])();
            break;
        }
    }
    else
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}