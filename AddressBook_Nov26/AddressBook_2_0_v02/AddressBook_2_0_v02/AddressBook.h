// Jason Creek cleanup done
// reviewed by Hoa Nguyen
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

using namespace std;

enum Title {Mr, Mrs, Ms, Dr};

struct NameType {
    Title title;
    string firstName;
    char middleInitial;
    string lastName;
};

struct AddressType {
    string street;
    string city;
    string state;
    string zip;
};

struct PhoneType {
    int areaCode;
    int prefix;
    int number;
};

struct SocialType {
    string email;
    string facebook;
    string twitter;
};

struct entryType {
    NameType name;
    AddressType address;
    PhoneType phone;
    SocialType socialmedia;
};

#endif
