#include "Vendor.h"
#include <iostream>
using namespace std;

Vendor::Vendor()
    : Contact(), serviceType(""), paymentTerms(""), accountNumber("") {}

Vendor::Vendor(const string& name, const string& phone,
               const string& email, const string& address,
               const string& city,
               const string& serviceType, const string& paymentTerms,
               const string& accountNumber)
    : Contact(name, phone, email, address, city),
      serviceType(serviceType), paymentTerms(paymentTerms),
      accountNumber(accountNumber) {}

void Vendor::setServiceType(const string& serviceType)     { this->serviceType   = serviceType;   }
void Vendor::setPaymentTerms(const string& paymentTerms)   { this->paymentTerms  = paymentTerms;  }
void Vendor::setAccountNumber(const string& accountNumber) { this->accountNumber = accountNumber; }

string Vendor::getServiceType()   const { return serviceType;   }
string Vendor::getPaymentTerms()  const { return paymentTerms;  }
string Vendor::getAccountNumber() const { return accountNumber; }

void Vendor::display() const {
    cout << "=== Vendor ===\n";
    Contact::display();
    cout << "Service Type:   " << serviceType   << "\n";
    cout << "Payment Terms:  " << paymentTerms  << "\n";
    cout << "Account Number: " << accountNumber << "\n";
}

string Vendor::getType() const {
    return "Vendor";
}

