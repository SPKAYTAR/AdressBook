#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <vector>
#include <string>
using namespace std;

class AddressBook
{
private:
	vector<Contact*> contacts;
public:
	AddressBook();
	~AddressBook();

	void addContact(Contact* contact);
	void editContact(int index);
	void deleteContact(int index);

	void viewContact(int index) const;
	void listContacts() const;

	void searchByName(const string& name) const;
	void searchByEmail(const string& email) const;
	void searchByPhone(const string& phone) const;

	void filterByType(const string& type) const;
	void filterByCity(const string& city) const;
	void filterByTag(const string& tag) const;

	void assignGroup(int index, const string& group);
	void addTag(int index, const string& tag);
	void removeTag(int index, const string& tag);

	void saveToFile(const string& filename) const;
	void loadFromFile(const string& filename);

	void listContactsByType() const;
	void showMissingInfo() const;
	void displayGroupSummaries() const;
};

#endif

