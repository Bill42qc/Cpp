#pragma once

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & ref);
		Bureaucrat & operator=(Bureaucrat const & ref);

		void				incrementGrade( void );
		void				decrementGrade( void );


		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		void				setGrade( const int new_grade);

		// Nested Exception classes:
		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		void signForm(Form & ref);
		void executeForm(Form const & form);

	private:
		const std::string	_name;
		int					_grade; 

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);