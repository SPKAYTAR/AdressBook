#include "Person.h"
#include <iostream>
using namespace std;

Person::Person()
    : Contact(), birthday(""), relationship("") {}

Person::Person(const string& name, const string& phone,
               const string& email, const string& address,
               const string& city,
               const string& birthday, const string& relationship)
    : Contact(name, phone, email, address, city),
      birthday(birthday), relationship(relationship) {}

void Person::setBirthday(const string& birthday)         { this->birthday     = birthday;     }
void Person::setRelationship(const string& relationship) { this->relationship = relationship; }

string Person::getBirthday()     const { return birthday;     }
string Person::getRelationship() const { return relationship; }

void Person::display() const {
    cout << "=== Person ===\n";
    Contact::display();
    cout << "Birthday:     " << birthday     << "\n";
    cout << "Relationship: " << relationship << "\n";
}

string Person::getType() const {
    return "Person";
}

