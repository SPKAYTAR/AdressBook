#include "EmergencyContact.h"
#include <iostream>
using namespace std;

EmergencyContact::EmergencyContact()
    : Contact(), relationship(""), priorityLevel(0), notes("") {}

EmergencyContact::EmergencyContact(const string& name, const string& phone,
                                   const string& email, const string& address,
                                   const string& city,
                                   const string& relationship, int priorityLevel,
                                   const string& notes)
    : Contact(name, phone, email, address, city),
      relationship(relationship), priorityLevel(priorityLevel), notes(notes) {}

void EmergencyContact::setRelationship(const string& relationship) { this->relationship  = relationship;  }
void EmergencyContact::setPriorityLevel(int priorityLevel)         { this->priorityLevel = priorityLevel; }
void EmergencyContact::setNotes(const string& notes)               { this->notes         = notes;         }

string EmergencyContact::getRelationship()  const { return relationship;  }
int    EmergencyContact::getPriorityLevel() const { return priorityLevel; }
string EmergencyContact::getNotes()         const { return notes;         }

void EmergencyContact::display() const {
    cout << "=== Emergency Contact ===\n";
    Contact::display();
    cout << "Relationship:   " << relationship  << "\n";
    cout << "Priority Level: " << priorityLevel << "\n";
    cout << "Notes:          " << notes         << "\n";
}

string EmergencyContact::getType() const {
    return "Emergency";
}

