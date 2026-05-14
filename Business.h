#ifndef BUSINESS_H
#define BUSINESS_H

#include "Contact.h"

class Business : public Contact {
private:
    string companyName;
    string jobTitle;
    string website;

public:
    Business();
    Business(const string& name, const string& phone,
             const string& email, const string& address,
             const string& city,
             const string& companyName, const string& jobTitle,
             const string& website);

    void setCompanyName(const string& companyName);
    void setJobTitle(const string& jobTitle);
    void setWebsite(const string& website);

    string getCompanyName() const;
    string getJobTitle()    const;
    string getWebsite()     const;

    void   display() const override;
    string getType() const override;
};

#endif // BUSINESS_H

