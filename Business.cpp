#include "Business.h"
#include <iostream>
using namespace std;

Business::Business()
    : Contact(), companyName(""), jobTitle(""), website("") {}

Business::Business(const string& name, const string& phone,
                   const string& email, const string& address,
                   const string& city,
                   const string& companyName, const string& jobTitle,
                   const string& website)
    : Contact(name, phone, email, address, city),
      companyName(companyName), jobTitle(jobTitle), website(website) {}

void Business::setCompanyName(const string& companyName) { this->companyName = companyName; }
void Business::setJobTitle(const string& jobTitle)       { this->jobTitle    = jobTitle;    }
void Business::setWebsite(const string& website)         { this->website     = website;     }

string Business::getCompanyName() const { return companyName; }
string Business::getJobTitle()    const { return jobTitle;    }
string Business::getWebsite()     const { return website;     }

void Business::display() const {
    cout << "=== Business ===\n";
    Contact::display();
    cout << "Company:   " << companyName << "\n";
    cout << "Job Title: " << jobTitle    << "\n";
    cout << "Website:   " << website     << "\n";
}

string Business::getType() const {
    return "Business";
}

