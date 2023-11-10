#pragma once
#include <iostream>

class Brain 
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
const std::string &getideas() const;

		
	protected:

	private:
		std::string ideas[100];
};