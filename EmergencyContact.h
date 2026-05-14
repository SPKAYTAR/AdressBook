#ifndef EMERGENCYCONTACT_H
#define EMERGENCYCONTACT_H

#include "Contact.h"

class EmergencyContact : public Contact {
private:
    string relationship;
    int    priorityLevel;
    string notes;

public:
    EmergencyContact();
    EmergencyContact(const string& name, const string& phone,
                     const string& email, const string& address,
                     const string& city,
                     const string& relationship, int priorityLevel,
                     const string& notes);

    void setRelationship(const string& relationship);
    void setPriorityLevel(int priorityLevel);
    void setNotes(const string& notes);

    string getRelationship()  const;
    int    getPriorityLevel() const;
    string getNotes()         const;

    void   display() const override;
    string getType() const override;
};

#endif // EMERGENCYCONTACT_H

