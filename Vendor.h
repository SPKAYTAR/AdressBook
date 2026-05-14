#ifndef VENDOR_H
#define VENDOR_H

#include "Contact.h"

class Vendor : public Contact {
private:
    string serviceType;
    string paymentTerms;
    string accountNumber;

public:
    Vendor();
    Vendor(const string& name, const string& phone,
           const string& email, const string& address,
           const string& city,
           const string& serviceType, const string& paymentTerms,
           const string& accountNumber);

    void setServiceType(const string& serviceType);
    void setPaymentTerms(const string& paymentTerms);
    void setAccountNumber(const string& accountNumber);

    string getServiceType()   const;
    string getPaymentTerms()  const;
    string getAccountNumber() const;

    void   display() const override;
    string getType() const override;
};

#endif // VENDOR_H

