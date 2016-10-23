#ifndef GETRECORD_H
#define GETRECORD_H

void GetName(std::ifstream&, NameType&);
void GetPhone(std::ifstream&, PhoneType&);
void GetAddress(std::ifstream&, AddressType&);
void GetState(std::ifstream&, AddressType&);
void GetSocialMedia(std::ifstream&, MediaType&);
bool GetRecord(std::ifstream&, entryType&);

#endif

