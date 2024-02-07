#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;  // Forward declaration

class Form {
public:
    Form(const std::string &name, int signGrade, int executeGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };


private:
    const std::string name;
    bool signedStatus;
    const int signGrade;
    const int executeGrade;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
