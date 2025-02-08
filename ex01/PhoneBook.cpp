#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    nextSlot = 0;
    numContacts = 0;
}

void PhoneBook::addContact(Contact contact) {
    contacts[nextSlot] = contact;
    std::cout << "Added new contact to slot #" << nextSlot << "\n";
    nextSlot = (nextSlot + 1) % MAX_CONTACTS;
    if (numContacts < MAX_CONTACTS) {
        numContacts++;
    }
}

void displayContactCol(std::string item) {
    std::cout << '|';
    if (item.length() > MAX_COL_WIDTH) {
        item = item.substr(0, MAX_COL_WIDTH - 1) + '.';
    }
    std::cout << std::setfill(' ') << std::setw(MAX_COL_WIDTH) << item;
}

void PhoneBook::displayAllContacts() {
    std::cout << "All saved contacts:\n";
    std::cout << std::setfill(' ') << std::setw(MAX_COL_WIDTH) << "Index";
    displayContactCol("First name");
    displayContactCol("Last name");
    displayContactCol("Nickname");
    std::cout << std::endl;
    for (int i = 0; i < numContacts; i++) {
        std::cout << std::setfill(' ') << std::setw(MAX_COL_WIDTH) << i;
        displayContactCol(contacts[i].getFirstName());
        displayContactCol(contacts[i].getLastName());
        displayContactCol(contacts[i].getNickname());
        std::cout << std::endl;
    }
}

void PhoneBook::displayContactInfo(int index) {
    if (index >= 0 && index < numContacts) {
        std::cout << "Displaying info for contact #0\n"
        <<"First name: " << contacts[index].getFirstName() << std::endl 
        << "Last name: " << contacts[index].getLastName() << std::endl
        << "Nickname: " << contacts[index].getNickname() << std::endl
        << "Phone number: " << contacts[index].getPhoneNumber() << std::endl
        << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
    } else {
        std::cout << "No contact for index #" << index << std::endl;
    }
    
}