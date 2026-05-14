#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact {
protected:
    string name;
    string phone;
    string email;
    string address;
    string city;

public:
    Contact();
    Contact(const string& name, const string& phone,
            const string& email, const string& address,
            const string& city);

    virtual ~Contact() = default;

    // Setters
    void setName(const string& name);
    void setPhone(const string& phone);
    void setEmail(const string& email);
    void setAddress(const string& address);
    void setCity(const string& city);

    // Getters
    string getName()    const;
    string getPhone()   const;
    string getEmail()   const;
    string getAddress() const;
    string getCity()    const;

    // Virtual interface
    virtual void   display() const;
    virtual string getType() const;
};

#endif // CONTACT_H

