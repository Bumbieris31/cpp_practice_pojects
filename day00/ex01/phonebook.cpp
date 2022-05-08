#include <phonebook.hpp>

void    PhoneBook::get_input() {
    std::string input;
    std::cout << "Phonebook is ready to be used...\nPlease enter a command:" << std::endl;
    while (1) {
        std::cin >> input;
        if (select_command(input))
	        std::cout << "Enter a new command:" << std::endl;
		else
			break;
    }
}

PhoneBook::PhoneBook() {
    current_contact = 0;
}

PhoneBook::~PhoneBook() {
    current_contact = 0;
}

bool    PhoneBook::select_command(std::string input) {
    if (input == "ADD")
        add();
    else if (input == "SEARCH")
        search();
	else if (input == "EXIT")
		return false;
	return true;
}
