#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "Creating a Bureaucrat with a valid grade (50):" << std::endl;
        Bureaucrat bureaucrat1("John", 50);
        std::cout << bureaucrat1 << std::endl;

        std::cout << "\nIncrementing the grade of the bureaucrat:" << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;

        std::cout << "\nDecrementing the grade of the bureaucrat:" << std::endl;
        bureaucrat1.decrementGrade();
        std::cout << bureaucrat1 << std::endl;

        std::cout << "Creating a Bureaucrat with a valid grade (50):" << std::endl;
        Bureaucrat bureaucrat3("boss", 1);
        bureaucrat3.incrementGrade();
        std::cout << bureaucrat3 << std::endl;

        std::cout << "Creating a Bureaucrat with a valid grade (50):" << std::endl;
        Bureaucrat bureaucrat4("visitor", 150);
        bureaucrat4.decrementGrade();
        std::cout << bureaucrat4 << std::endl;

        // std::cout << "\nCreating a Bureaucrat with a too high grade (0, should throw GradeTooHighException):" << std::endl;
        // Bureaucrat invalidBureaucrat1("Alice", 0);

        // std::cout << "\nCreating a Bureaucrat with a too low grade (160, should throw GradeTooLowException):" << std::endl;
        // Bureaucrat invalidBureaucrat2("Bob", 160);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}