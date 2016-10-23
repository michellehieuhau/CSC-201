
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

enum Title {Mr, Mrs, Ms, Dr};

struct NameType
{
    Title title;
    std::string firstName;
    char middleInitial;
    std::string lastName;
};

struct AddressType
{
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
};

struct PhoneType
{
    int areaCode;
    int prefix;
    int number;
};

struct MediaType
 {
    std::string email;
    std::string facebook;
    std::string twitter;
 };

struct entryType
{
    NameType name;
    AddressType address;
    PhoneType phone;
    MediaType media;
};

#endif // ADDRESSBOOK_H

