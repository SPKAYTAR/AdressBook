#include "AddressBook.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

AddressBook::AddressBook() {}

AddressBook::~AddressBook()
{
    for (Contact* contact : contacts)
    {
        delete contact;
    }
    contacts.clear();
}

void AddressBook::addContact(Contact* contact)
{
    if (contact != nullptr)
    {
        contacts.push_back(contact);
        cout << "Contact added.\n";
    }
}

void AddressBook::editContact(int index)
{
    if (index < 0 || index >= contacts.size())
    {
        cout << "Invalid contact index.\n";
        return;
    }

    string name;
    string phone;
    string email;
    string address;
    string city;

    cout << "Enter new name: ";
    getline(cin, name);

    cout << "Enter new phone: ";
    getline(cin, phone);

    cout << "Enter new email: ";
    getline(cin, email);

    cout << "Enter new address: ";
    getline(cin, address);

    cout << "Enter new city: ";
    getline(cin, city);

    contacts[index]->setName(name);
    contacts[index]->setPhone(phone);
    contacts[index]->setEmail(email);
    contacts[index]->setAddress(address);
    contacts[index]->setCity(city);

    cout << "Contact updated.\n";
}

void AddressBook::deleteContact(int index)
{
    if (index < 0 || index >= contacts.size())
    {
        cout << "Invalid contact index.\n";
        return;
    }

    delete contacts[index];
    contacts.erase(contacts.begin() + index);

    cout << "Contact deleted.\n";
}

void AddressBook::viewContact(int index) const
{
    if (index < 0 || index >= contacts.size())
    {
        cout << "Invalid contact index.\n";
        return;
    }

    contacts[index]->display();
}

void AddressBook::listContacts() const
{
    if (contacts.empty())
    {
        cout << "No contacts found.\n";
        return;
    }

    for (int i = 0; i < contacts.size(); i++)
    {
        cout << "\n Contact #" << i << endl;
        contacts[i]->display();
    }
}

void AddressBook::searchByName(const string& name) const
{
    bool found = false;

    for (Contact* contact : contacts)
    {
        if (contact->getName() == name)
        {
            contact->display();
            found = true;
        }
    }

    if (!found)
        cout << "No contact found with that name.\n";
}

void AddressBook::searchByEmail(const string& email) const
{
    bool found = false;

    for (Contact* contact : contacts)
    {
        if (contact->getEmail() == email)
        {
            contact->display();
            found = true;
        }
    }

    if (!found)
        cout << "No contact found with that email.\n";
}

void AddressBook::searchByPhone(const string& phone) const
{
    bool found = false;

    for (Contact* contact : contacts)
    {
        if (contact->getPhone() == phone)
        {
            contact->display();
            found = true;
        }
    }

    if (!found)
        cout << "No contact found with that phone number.\n";
}

void AddressBook::filterByType(const string& type) const
{
    bool found = false;

    for (Contact* contact : contacts)
    {
        if (contact->getType() == type)
        {
            contact->display();
            found = true;
        }
    }

    if (!found)
        cout << "No contact found with that type.\n";
}

void AddressBook::filterByCity(const string& city) const
{
    bool found = false;

    for (Contact* contact : contacts)
    {
        if (contact->getCity() == city)
        {
            contact->display();
            found = true;
        }
    }

    if (!found)
        cout << "No contact found in that city.\n";
}

void AddressBook::filterByTag(const string& tag) const
{
}

void AddressBook::assignGroup(int index, const string& group)
{
}

void AddressBook::addTag(int index, const string& tag)
{
}

void AddressBook::removeTag(int index, const string& tag)
{
}

void AddressBook::saveToFile(const string& filename) const
{
    ofstream outFile(filename);

    if (!outFile)
    {
        cout << "Error opening file.\n";
        return;
    }

    for (Contact* contact : contacts)
    {
        outFile << contact->getName() << endl;
        outFile << contact->getPhone() << endl;
        outFile << contact->getEmail() << endl;
        outFile << contact->getAddress() << endl;
        outFile << contact->getCity() << endl;
    }

    outFile.close();
    cout << "Contacts saved.\n";
}

void AddressBook::loadFromFile(const string& filename)
{
    ifstream inFile(filename);

    if (!inFile)
    {
        cout << "Error opening file.\n";
        return;
    }

    string name, phone, email, address, city;

    while (getline(inFile, name) &&
        getline(inFile, phone) &&
        getline(inFile, email) &&
        getline(inFile, address) &&
        getline(inFile, city))
    {
        contacts.push_back(new Contact(name, phone, email, address, city));
    }

    inFile.close();
    cout << "Contacts loaded from file.\n";
}

void AddressBook::listContactsByType() const
{
    for (Contact* contact : contacts)
    {
        cout << "\nType: " << contact->getType() << endl;
        contact->display();
    }
}

void AddressBook::showMissingInfo() const
{
    bool found = false;

    for (Contact* contact : contacts)
    {
        if (contact->getName() == "" ||
            contact->getPhone() == "" ||
            contact->getEmail() == "" ||
            contact->getAddress() == "" ||
            contact->getCity() == "")
        {
            contact->display();
            found = true;
        }
    }

    if (!found)
        cout << "No contacts with missing information.\n";
}

void AddressBook::displayGroupSummaries() const
{
}

