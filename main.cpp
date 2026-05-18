#include "AddressBook.h"
#include "Menu.h"

int main() {
    AddressBook book;
    book.loadFromFile("contacts.csv");  // loads saved contacts on startup
                                        // silently skips if file doesn't exist yet

    Menu menu(book);
    menu.run();                         // hands control to the console UI

    book.saveToFile("contacts.csv");    // saves everything on exit
    return 0;
}
