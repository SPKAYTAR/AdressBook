#include "Menu.h"
#include <iostream>
#include <limits>

#include "AddressBook.h"

using namespace std;

Menu::Menu() {
    book.loadFromFile("contacts.csv"); // loads saved contacts on startup
                                                  // silently skips if file doesn't exist yet
}

Menu::~Menu() {}

void Menu::printHeader(const string& title) {
    cout << "\n=============================================\n";
    cout << "  " << title << "\n";
    cout << "=============================================\n";
}
void Menu::pauseAndClear() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << string(50, '\n');
}
int Menu::getValidIntegerChoice(int min, const int max) {
    int choice;
    while (true) {
        cout << "Enter your choice (" << min << "-" << max << "): ";
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        } else {
            cout << "Invalid input. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void Menu::run() {
    bool running = true;
    while (running) {
        printHeader("ADDRESS BOOK - MAIN MENU");
        cout << "1. Manage Contacts (Add/Edit/Delete/View)\n";
        cout << "2. Search and Filter\n";
        cout << "3. Grouping and Tagging\n";
        cout << "4. Import / Export (Save/Load)\n";
        cout << "5. Reports\n";
        cout << "6. Exit\n";

        int choice = getValidIntegerChoice(1, 6);

        switch (choice) {
            case 1: {
                bool managing = true;
                while (managing) {
                    printHeader("CONTACT MANAGEMENT");
                    cout << "1. Add a new contact\n";
                    cout << "2. Edit an existing contact\n";
                    cout << "3. Delete a contact\n";
                    cout << "4. View a single contact's details\n";
                    cout << "5. List all contacts\n";
                    cout << "6. Back to Main Menu\n";

                    int subChoice = getValidIntegerChoice(1, 6);
                    switch (subChoice) {
                        case 1: handleAddContact(); break;
                        case 2: handleEditContact(); break;
                        case 3: handleDeleteContact(); break;
                        case 4: handleViewContact(); break;
                        case 5: handleListContacts(); break;
                        case 6: managing = false; break;
                    }
                }
                break;
            }
            case 2: handleSearchAndFilter(); break;
            case 3: handleGroupingAndTagging(); break;
            case 4: handleImportExport(); break;
            case 5: handleReports(); break;
            case 6: 
                running = false; 
                cout << "Exiting Address Book. Goodbye!\n";
                break;
        }
    }
}

void Menu::handleAddContact() {
    printHeader("ADD NEW CONTACT");
    cout << "Select Contact Type:\n";
    cout << "1. Person\n";
    cout << "2. Business\n";
    cout << "3. Vendor\n";
    cout << "4. Emergency\n";
    cout << "5. Cancel\n";

    int typeChoice = getValidIntegerChoice(1, 5);
    if (typeChoice == 5) return;

    // Base attributes
    string name, phone, email, address, city;
    cout << "Name: ";
    getline(cin, name);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Email: ";
    getline(cin, email);
    cout << "Address: ";
    getline(cin, address);
    cout << "City: ";
    getline(cin, city);

    // TODO: MISSING FUNCTIONALITY - Backend integration
    // Currently, this creates the object and pushes it to a local vector.
    // Replace this logic with your backend/AddressBook manager.
    
    switch (typeChoice) {
        case 1: {
            string bday, rel;
            cout << "Birthday: "; getline(cin, bday);
            cout << "Relationship: "; getline(cin, rel);
            auto* newPer = new Person(name, phone, email, address, city, bday, rel);
            book.addContact(newPer);
            break;
        }
        case 2: {
            string comp, title, web;
            cout << "Company Name: "; getline(cin, comp);
            cout << "Job Title: "; getline(cin, title);
            cout << "Website: "; getline(cin, web);
            auto* newBus = new Business(name, phone, email, address, city, comp, title, web);
            book.addContact(newBus);
            break;
        }
        case 3: {
            string service, terms, acc;
            cout << "Service Type: "; getline(cin, service);
            cout << "Payment Terms: "; getline(cin, terms);
            cout << "Account Number: "; getline(cin, acc);
            auto* newVend = new Vendor(name, phone, email, address, city, service, terms, acc);
            book.addContact(newVend);
            break;
        }
        case 4: {
            string rel, notes;
            int prio;
            cout << "Relationship: "; getline(cin, rel);
            cout << "Priority Level (e.g., 1-10): "; 
            cin >> prio;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Notes: ";
            getline(cin, notes);
            auto* newEmer = new EmergencyContact(name, phone, email, address, city, rel, prio, notes);
            book.addContact(newEmer);
            break;
        }
    }
    cout << "Contact added successfully!\n";
    pauseAndClear();
}

void Menu::handleEditContact() {
    printHeader("EDIT CONTACT");

    book.listContacts();
    cout << endl;

    int index;
    cout << "Select contact index";
    cin >> index;

    book.editContact(index);

    pauseAndClear();
}

void Menu::handleDeleteContact() {
    printHeader("DELETE CONTACT");

    book.listContacts();
    cout << endl;

    int index;
    cout << "Select contact index";
    cin >> index;

    book.deleteContact(index);

    pauseAndClear();
}

void Menu::handleViewContact() {
    printHeader("VIEW CONTACT DETAILS");

    book.listContacts();
    cout << endl;

    int index;
    cout << "Select contact index";
    cin >> index;

    book.viewContact(index);

    pauseAndClear();
}

void Menu::handleListContacts() {
    book.listContacts();
    pauseAndClear();
}

void Menu::handleSearchAndFilter() {
    printHeader("SEARCH AND FILTER");
    cout << "1. Search by Name/Email/Phone\n";
    cout << "2. Filter by Type/City/Tag\n";
    cout << "3. Cancel\n";
    
    int choice = getValidIntegerChoice(1, 3);

    if (choice == 1) {
        printHeader("Select Search Mode");
        int searchMode = getValidIntegerChoice(1,3);
        switch (searchMode)
        {
            case 1:
                {
                    cout << "Enter contact name: ";
                    string name;
                    getline(cin, name);
                    book.searchByName(name);
                    break;
                }
            case 2:
                {
                    cout << "Enter contact Email: ";
                    string email;
                    getline(cin, email);
                    book.searchByEmail(email);
                    break;
                }
            case 3:
                {
                    cout << "Enter contact Phone: ";
                    string phone;
                    getline(cin, phone);
                    book.searchByPhone(phone);
                    break;
                }
        }
    }
    if (choice == 2)
    {
        printHeader("Select Filter Mode");
        int  filterMode = getValidIntegerChoice(1, 3);
        switch (filterMode)
        {
        case 1:
            {
                cout << "Enter contact type: ";
                string type;
                getline(cin, type);
                book.filterByType(type);
                break;
            }
        case 2:
            {
                cout << "Enter contact city: ";
                string city;
                getline(cin, city);
                book.searchByEmail(city);
                break;
            }
        case 3:
            {
                cout << "Enter contact tag: ";
                string tag;
                getline(cin, tag);
                book.searchByPhone(tag);
                break;
            }
        }
    }

    if (choice == 3) return;

    pauseAndClear();
}

void Menu::handleGroupingAndTagging() {
    printHeader("GROUPING AND TAGGING");
    cout << "1. Assign contact to a Group (Family, Work, Vendors)\n";
    cout << "2. Add/Remove Tags (Important, Client, Friend)\n";
    cout << "3. Cancel\n";
    
    int choice = getValidIntegerChoice(1, 3);

    book.listContacts();

    switch (choice)
    {
        case 1:
            {
                book.listContacts();
                cout << endl;

                int index;
                string group;

                cout << "Select contact index: ";
                cin >> index;
                cin.ignore();

                cout << "Enter group(Family, Work, Vendors): ";
                getline(cin, group);

                book.assignGroup(index, group);

                break;
            }
        case 2:
            {
                cout << "Do you want to add(1) or remove(2) tag?";
                int addRemove = getValidIntegerChoice(1, 2);

                book.listContacts();
                cout << endl;
                switch (addRemove)
                {
                    case 1:
                        {
                            int index;
                            string tag;

                            cout << "Select contact index: ";
                            cin >> index;
                            cin.ignore();

                            cout << "Enter tag: ";
                            getline(cin, tag);

                            book.addTag(index, tag);

                            break;
                        }
                    case 2:
                        {
                            int index;
                            string tag;

                            cout << "Select contact index: ";
                            cin >> index;
                            cin.ignore();

                            cout << "Enter tag: ";
                            getline(cin, tag);

                            book.addTag(index, tag);

                            break;
                        }
                }
            }
    }

    if (choice == 3) return;

    pauseAndClear();
}

void Menu::handleImportExport() {
    printHeader("IMPORT / EXPORT");
    cout << "1. Save contacts to CSV/Text\n";
    cout << "2. Load contacts from CSV/Text\n";
    cout << "3. Cancel\n";
    
    int choice = getValidIntegerChoice(1, 3);

    switch (choice)
    {
        case 1: book.saveToFile("contacts.csv");
                break;
        case 2: book.loadFromFile("contacts.csv");
                break;
        default: return;
    }

    pauseAndClear();
}

void Menu::handleReports() {
    printHeader("REPORTS");
    cout << "1. List contacts by type\n";
    cout << "2. Show contacts missing email or phone\n";
    cout << "3. Display group summaries\n";
    cout << "4. Cancel\n";

    const int choice = getValidIntegerChoice(1, 4);

    switch (choice)
    {
        case 1: book.listContactsByType();
                break;
        case 2: book.showMissingInfo();
                break;
        case 3: book.displayGroupSummaries();
                break;
        default: return;
    }

    pauseAndClear();
}

void Menu::saveToFile(const char* str) {
    book.saveToFile(str);
}

