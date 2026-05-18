#include "AddressBook.h"
#include "Menu.h"

int main() {
    Menu menu{};
    menu.run();                         // hands control to the console UI

    menu.saveToFile("contacts.csv");    // saves everything on exit
    return 0;
}
