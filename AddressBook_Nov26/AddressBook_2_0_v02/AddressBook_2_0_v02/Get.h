// Jason Creek
// reviewed by Hoa Nguyen
#ifndef GET_H_INCLUDED
#define GET_H_INCLUDED
// function prototypes for all functions that are used to get the info from the file
bool GetRecord(ifstream&, entryType[], int);
void GetName(ifstream&, entryType[], int);
void GetPhone(ifstream&, entryType[], int);
void GetAddress(ifstream&, entryType[], int);
void GetState(ifstream&, entryType[], int);
void GetSocialM (ifstream&, entryType[], int); // added new get function
//string GetTitle(Title);

#endif // GET_H_INCLUDED
