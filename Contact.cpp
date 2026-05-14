#include "Contact.h"
#include <iostream>
using namespace std;

Contact::Contact()
    : name(""), phone(""), email(""), address(""), city("") {}

Contact::Contact(const string& name, const string& phone,
                 const string& email, const string& address,
                 const string& city)
    : name(name), phone(phone), email(email),
      address(address), city(city) {}

// Setters
void Contact::setName(const string& name)       { this->name    = name;    }
void Contact::setPhone(const string& phone)     { this->phone   = phone;   }
void Contact::setEmail(const string& email)     { this->email   = email;   }
void Contact::setAddress(const string& address) { this->address = address; }
void Contact::setCity(const string& city)       { this->city    = city;    }

// Getters
string Contact::getName()    const { return name;    }
string Contact::getPhone()   const { return phone;   }
string Contact::getEmail()   const { return email;   }
string Contact::getAddress() const { return address; }
string Contact::getCity()    const { return city;    }

// Virtual functions
void Contact::display() const {
    cout << "Name:    " << name    << "\n";
    cout << "Phone:   " << phone   << "\n";
    cout << "Email:   " << email   << "\n";
    cout << "Address: " << address << "\n";
    cout << "City:    " << city    << "\n";
}

string Contact::getType() const {
    return "Contact";
}

