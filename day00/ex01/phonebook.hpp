#ifndef CPP_PHONEBOOK_H
# define CPP_PHONEBOOK_H

# include <stdlib.h>
# include <iostream>
# include <iomanip>
# include <string>


class Contact {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
public:
    Contact();
    void set_first_name(std::string str);
    void set_last_name(std::string str);
    void set_nickname(std::string str);
    void set_phone_number(std::string str);
    void set_darkest_secret(std::string str);
    void print_contact();
    void get_input();
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_darkest_secret() const;
    bool empty;
};

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    int ask_for_contact();
    void add();
    void get_input();
    void search();
    bool select_command(std::string input);
    void display_search_options();
    void display_one_contact(int id);
	static std::string shorten_string(std::string str);
    Contact book[8];
    int current_contact;
};

std::ostream& operator<<(std::ostream& os, const Contact& cont);

#endif //CPP_PHONEBOOK_H
