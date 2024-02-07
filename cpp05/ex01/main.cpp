#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat1("John Doe", 50);
        Bureaucrat bureaucrat2("Jane Doe", 1);

        Form form1("Tax Form", 30, 25);
        Form form2("Approval Form", 2, 10);

        // Display initial state
        std::cout << "Initial State:\n";
        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        // Attempt to sign forms
        bureaucrat1.signForm(form1);
        bureaucrat2.signForm(form2);

        // Display updated state
        std::cout << "\nUpdated State:\n";
        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        // Attempt to sign form2 with bureaucrat2 (should fail)
        bureaucrat2.signForm(form2);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
