#include "phonebook.hpp"


void    PhoneBook::add() {
    book[current_contact % 8].get_input();
    current_contact++;
}

void    PhoneBook::search() {
    if (current_contact == 0)
		std::cout << "No contact has been entered" << std::endl;
	else {
    	display_search_options();
    	display_one_contact(ask_for_contact());
	}
}

void    PhoneBook::display_search_options() {
    std::cout << "        Id|First name| Last name|  Nickname\n"
    << "----------|----------|----------|----------" << std::endl;;
    for (int i = 0; i < 8; i++) {
        if (book[i].empty == false) {
            std::cout << std::right << std::setw(10) << i
            << "|" << std::setw(10) << shorten_string(book[i].get_first_name())
            << "|" << std::setw(10) << shorten_string(book[i].get_last_name())
            << "|" << std::setw(10) << shorten_string(book[i].get_nickname())
            << std::endl << "----------|----------|----------|----------" << std::endl;
        }
    }
}

std::string PhoneBook::shorten_string(std::string str) {
	if (str.size() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

int     PhoneBook::ask_for_contact() {
    int id_request;
    while (1) {
        std::cout << "Please enter valid id:";
        std::cin >> id_request;
        if (not std::cin.fail())
            if (0 <= id_request and id_request < 8)
                if(not book[id_request].empty)
                    break;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    return id_request;
}

void    PhoneBook::display_one_contact(int id) {
    std::cout << book[id] << std::endl; // remove 2endl?
}