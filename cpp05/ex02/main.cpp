#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Test 1: Create a bureaucrat named "John" with a grade of 50
        Bureaucrat bureaucrat("John", 50);
        std::cout << "Test 1: Create a bureaucrat named 'John' with a grade of 50" << std::endl;
        std::cout << bureaucrat << std::endl << std::endl;

        // Test 2: Create three different forms
        ShrubberyCreationForm shrubberyForm("Garden");
        RobotomyRequestForm robotomyForm("Human");
        PresidentialPardonForm pardonForm("Criminal");
        std::cout << "Test 2: Create ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm" << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl << std::endl;

        // Test 3: Display the state of the bureaucrat and forms after creation
        std::cout << "Test 3: Display the state of the bureaucrat and forms after creation" << std::endl;
        std::cout << bureaucrat << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl << std::endl;

        // Test 4: Bureaucrat signs each form
        std::cout << "Test 4: Bureaucrat signs Forms" << std::endl;
        bureaucrat.signForm(shrubberyForm);
        bureaucrat.signForm(robotomyForm);
        bureaucrat.signForm(pardonForm);
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl << std::endl;

        // Test 5: Display the state of the forms after signing
        std::cout << "Test 5: Display the state of the forms after signing" << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl << std::endl;

        // Test 6: Bureaucrat executes each form
        std::cout << "Test 6: Bureaucrat executes ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm" << std::endl;
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);
    } catch (const std::exception &e) {
        // Handle exceptions and display error messages
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
