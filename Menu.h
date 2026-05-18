#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

#include "AddressBook.h"
#include "Contact.h"
#include "Person.h"
#include "Business.h"
#include "Vendor.h"
#include "EmergencyContact.h"

class Menu {
private:
    AddressBook book;

    // UI Display Helpers
    static void printHeader(const std::string& title) ;
    static void pauseAndClear() ;
    static int getValidIntegerChoice(int min, int max) ;

    // Sub-menus & Handlers
    void handleAddContact();
    void handleEditContact();
    void handleDeleteContact();
    void handleViewContact();
    void handleListContacts();

    void handleSearchAndFilter();
    void handleGroupingAndTagging();
    void handleImportExport();
    void handleReports();

public:
    Menu();
    ~Menu();

    // Main entry point for the console loop
    void run();
    void saveToFile(const char* str);
};

#endif // MENU_H