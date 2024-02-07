#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : name(name), signedStatus(false), signGrade(signGrade), executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), signedStatus(other.signedStatus),
      signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecuteGrade() const {
    return executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade) {
        signedStatus = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << ", Sign Grade: " << form.getSignGrade()
        << ", Execute Grade: " << form.getExecuteGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
    return out;
}
