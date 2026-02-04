#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
    private:
        Contact         _contacts[8];
        size_t          _index;
        int             _count;


    public:
                        PhoneBook();
        void            add();
        void            search();
        void            help();

};

#endif