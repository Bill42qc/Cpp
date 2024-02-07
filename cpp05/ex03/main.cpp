#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    std::srand(std::time(0)); // Common practice to seed the pseudo-random number generator

    std::cout << "CONSTRUCTING:" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Intern intern;
    Form *roboForm;
    Form *shrubForm;
    Form *presidentForm;
    Form *unknownForm;

    std::cout << std::endl << std::endl;

    std::cout << "INTERN TESTS:" << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Robo:
    roboForm = intern.makeForm("robotomy request", "robo");
    std::cout << *roboForm << " was just created" << std::endl << std::endl;

    // President:
    presidentForm = intern.makeForm("presidential pardon", "president");
    std::cout << *presidentForm << " was just created" << std::endl << std::endl;

    // Shrub:
    shrubForm = intern.makeForm("shrubbery creation", "shrub");
    std::cout << *shrubForm << " was just created" << std::endl << std::endl;

    // Unknown:
    try {
        unknownForm = intern.makeForm("driving licence", "drive");
        std::cout << *unknownForm << " was just created" << std::endl << std::endl;
    } catch (Intern::Exception &e) {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Don't forget to delete dynamically allocated memory
    delete roboForm;
    delete shrubForm;
    delete presidentForm;
    delete unknownForm;

    return 0;
}
