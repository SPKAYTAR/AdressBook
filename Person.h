#ifndef PERSON_H
#define PERSON_H

#include "Contact.h"

class Person : public Contact {
private:
    string birthday;
    string relationship;

public:
    Person();
    Person(const string& name, const string& phone,
           const string& email, const string& address,
           const string& city,
           const string& birthday, const string& relationship);

    void setBirthday(const string& birthday);
    void setRelationship(const string& relationship);

    string getBirthday()     const;
    string getRelationship() const;

    void   display() const override;
    string getType() const override;
};

#endif // PERSON_H

