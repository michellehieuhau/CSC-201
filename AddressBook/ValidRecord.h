#ifndef VALIDRECORD_H
#define VALIDRECORD_H

using namespace std;

void TrimSpaces(string&);
string NormalizeString(string);
bool ValidName(string);
bool ValidAddress(AddressType);
bool ValidPhone(string);
bool ValidMedia(string, char);

#endif
