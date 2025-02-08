#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MAX_COL_WIDTH 10

class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        int nextSlot;
        int numContacts;

    public:
        PhoneBook();

        void addContact(Contact contact);
        void displayAllContacts();
        void displayContactInfo(int index);
};

#endif