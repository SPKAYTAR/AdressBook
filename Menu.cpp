#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu() {
    // Constructor: could load contacts from file automatically here via handleImportExport()
}

Menu::~Menu() {
    // Clean up dynamically allocated memory
    for (Contact* c : contactList) {
        delete c;
    }
    contactList.clear();
}

void Menu::printHeader(const string& title) {
    cout << "\n=============================================\n";
    cout << "  " << title << "\n";
    cout << "=============================================\n";
}
void Menu::pauseAndClear() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // cin.get(); // Optional depending on how buffering is handled
    
    // Quick pseudo-clear for standard console
    cout << string(50, '\n'); 
}
int Menu::getValidIntegerChoice(int min, int max) {
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
            contactList.push_back(new Person(name, phone, email, address, city, bday, rel));
            break;
        }
        case 2: {
            string comp, title, web;
            cout << "Company Name: "; getline(cin, comp);
            cout << "Job Title: "; getline(cin, title);
            cout << "Website: "; getline(cin, web);
            contactList.push_back(new Business(name, phone, email, address, city, comp, title, web));
            break;
        }
        case 3: {
            string service, terms, acc;
            cout << "Service Type: "; getline(cin, service);
            cout << "Payment Terms: "; getline(cin, terms);
            cout << "Account Number: "; getline(cin, acc);
            contactList.push_back(new Vendor(name, phone, email, address, city, service, terms, acc));
            break;
        }
        case 4: {
            string rel, notes;
            int prio;
            cout << "Relationship: "; getline(cin, rel);
            cout << "Priority Level (e.g., 1-10): "; 
            cin >> prio;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Notes: "; getline(cin, notes);
            contactList.push_back(new EmergencyContact(name, phone, email, address, city, rel, prio, notes));
            break;
        }
    }
    cout << "Contact added successfully!\n";
    pauseAndClear();
}

void Menu::handleEditContact() {
    printHeader("EDIT CONTACT");
    cout << "[MISSING FUNCTIONALITY]: Backend logic to select a contact and modify their attributes is not yet implemented.\n";
    cout << "Placeholder: Allow user to search/select a contact, choose an attribute, and update the string value.\n";
    pauseAndClear();
}

void Menu::handleDeleteContact() {
    printHeader("DELETE CONTACT");
    cout << "[MISSING FUNCTIONALITY]: Backend logic to find and remove a contact from the data structure is not yet implemented.\n";
    pauseAndClear();
}

void Menu::handleViewContact() {
    printHeader("VIEW CONTACT DETAILS");
    cout << "[MISSING FUNCTIONALITY]: Backend logic to search for a specific contact and call their display() method is not yet implemented.\n";
    pauseAndClear();
}

void Menu::handleListContacts() {
    printHeader("ALL CONTACTS");
    // This is a basic implementation using the temporary vector.
    if (contactList.empty()) {
        cout << "No contacts found.\n";
    } else {
        for (size_t i = 0; i < contactList.size(); ++i) {
            cout << "\n--- Contact #" << i + 1 << " (" << contactList[i]->getType() << ") ---\n";
            contactList[i]->display();
        }
    }
    pauseAndClear();
}

void Menu::handleSearchAndFilter() {
    printHeader("SEARCH AND FILTER");
    cout << "1. Search by Name/Email/Phone\n";
    cout << "2. Filter by Type/City/Tag\n";
    cout << "3. Cancel\n";
    
    int choice = getValidIntegerChoice(1, 3);
    if (choice == 3) return;

    cout << "\n[MISSING FUNCTIONALITY]: Backend search algorithms (e.g., substring matching, type filtering) are not yet implemented.\n";
    pauseAndClear();
}

void Menu::handleGroupingAndTagging() {
    printHeader("GROUPING AND TAGGING");
    cout << "1. Assign contact to a Group (Family, Work, Vendors)\n";
    cout << "2. Add/Remove Tags (Important, Client, Friend)\n";
    cout << "3. Cancel\n";
    
    int choice = getValidIntegerChoice(1, 3);
    if (choice == 3) return;

    cout << "\n[MISSING FUNCTIONALITY]: Tagging and grouping data structures (like maps or vectors inside the Contact class) are not yet implemented.\n";
    pauseAndClear();
}

void Menu::handleImportExport() {
    printHeader("IMPORT / EXPORT");
    cout << "1. Save contacts to CSV/Text\n";
    cout << "2. Load contacts from CSV/Text\n";
    cout << "3. Cancel\n";
    
    int choice = getValidIntegerChoice(1, 3);
    if (choice == 3) return;

    cout << "\n[MISSING FUNCTIONALITY]: File I/O operations (fstream) for parsing and writing contact data are not yet implemented.\n";
    pauseAndClear();
}

void Menu::handleReports() {
    printHeader("REPORTS");
    cout << "1. List contacts by type\n";
    cout << "2. Show contacts missing email or phone\n";
    cout << "3. Display group summaries\n";
    cout << "4. Cancel\n";

    int choice = getValidIntegerChoice(1, 4);
    if (choice == 4) return;

    cout << "\n[MISSING FUNCTIONALITY]: Backend aggregation and reporting logic is not yet implemented.\n";
    pauseAndClear();
}