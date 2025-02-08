#include <iostream>
#include <sstream>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void safeGetLine(std::string &str) {
    if (!std::getline(std::cin, str)) {
        std::cerr << "Error while getting input. Byebye!";
        exit(EXIT_FAILURE);
    }
}

void getNonEmptyField(std::string &str) {
    safeGetLine(str);
    while (str.empty()) {
        std::cout << "Field can't be empty. Enter again: ";
        safeGetLine(str);
    }
}


Contact getContactFromUser() {
    std::string firstName;
    std::string lastName;
    std::string nickname; 
    std::string phoneNumber;
    std::string darkestSecret;
    
    std::cout << "Ok! Let's add a new contact. \nFirst name: ";
    getNonEmptyField(firstName);
    std::cout << "Last name: ";
    getNonEmptyField(lastName);
    std::cout << "Nickname: ";
    getNonEmptyField(nickname);
    std::cout << "Phone number: ";
    getNonEmptyField(phoneNumber);
    std::cout << "Darkest secret: ";
    getNonEmptyField(darkestSecret);
    return Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

int getIndexFromUser() {
    std::string input;
    int index;
    char remaining;

    std::cout << "Type in index of contact: ";
    
    while (true) {
        safeGetLine(input);
        std::stringstream ss(input);
        if (ss >> index) {
            if (!(ss>> remaining)) {
                return index;
            } else {
                std::cout << "Please enter a valid integer: ";
            }
            
        } else {
            std::cout << "Please enter an integer: ";
        }
    }
    
    
}



int main() {
    PhoneBook phonebook;

    std::string input;

    do {
        std::cout << "Please tell me what to do: ";
        safeGetLine(input);
        if (input == "ADD") {
            phonebook.addContact(getContactFromUser());
        } else if (input == "SEARCH") {
            phonebook.displayAllContacts();
            phonebook.displayContactInfo(getIndexFromUser());
        } else if (input != "EXIT") {
            std::cout << "Try again. Valid commands are ADD, SEARCH and EXIT. \n";
        }
    } while (input != "EXIT");
    std::cout << "Byebye!\n";
}
