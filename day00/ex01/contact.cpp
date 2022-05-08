#include <phonebook.hpp>


void    Contact::set_first_name(std::string str) {
    first_name = str;
}

void    Contact::set_last_name(std::string str) {
    last_name = str;
}

void    Contact::set_nickname(std::string str) {
    nickname = str;
}

void    Contact::set_phone_number(std::string str) {
    phone_number = str;
}

void    Contact::set_darkest_secret(std::string str) {
    darkest_secret = str;
}

std::string Contact::get_first_name() const {
    return first_name;
}

std::string Contact::get_last_name() const {
    return last_name;
}

std::string Contact::get_nickname() const {
    return nickname;
}

std::string Contact::get_phone_number() const {
    return phone_number;
}

std::string Contact::get_darkest_secret() const {
    return darkest_secret;
}

std::ostream& operator<<(std::ostream& os, const Contact& cont) {
    if (cont.empty != true) {
        os << cont.get_first_name() << std::endl;
        os << cont.get_last_name() << std::endl;
        os << cont.get_nickname() << std::endl;
        os << cont.get_phone_number() << std::endl;
        os << cont.get_darkest_secret() << std::endl;
    }
    return os;
}

void    Contact::get_input(void) {
    std::string f_name, l_name, n_name, p_number, d_secret;
    std::cout << "Please enter the First Name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, f_name);
    set_first_name(f_name);
    std::cout << "Please enter the Last Name: " << std::endl;
//    std::cin.ignore();
    std::getline(std::cin, l_name);
    set_last_name(l_name);
    std::cout << "Please enter the Nickname: " << std::endl;
//    std::cin.ignore();
    std::getline(std::cin, n_name);
    set_nickname(n_name);
    std::cout << "Please enter the Phone Number: " << std::endl;
//    std::cin.ignore();
    std::getline(std::cin, p_number);
    set_phone_number(p_number);
    std::cout << "Please enter the Darkest Secret: " << std::endl;
//    std::cin.ignore();
    std::getline(std::cin, d_secret);
    set_darkest_secret(d_secret);
    empty = false;
    std::cout << "Contact added!" << std::endl;
}

Contact::Contact() {
    empty = true;
};
