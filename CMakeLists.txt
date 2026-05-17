cmake_minimum_required(VERSION 4.2)
project(AdressBook)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AdressBook
        AddressBook.cpp
        AddressBook.h
        Business.cpp
        Business.h
        Contact.cpp
        Contact.h
        EmergencyContact.cpp
        EmergencyContact.h
        main.cpp
        Menu.cpp
        Menu.h
        Person.cpp
        Person.h
        Vendor.cpp
        Vendor.h)
