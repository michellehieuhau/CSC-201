// Jason Creek
// reviewed by Hoa Nguyen
#include <iostream>
#include <string>
#include <fstream>
#include "AddressBook.h"
#include "Get.h"
#include "Print.h"

using namespace std;

// Debug flag added for easy trouble shooting during dev.
bool DebugP = false;
/* PrintAddressBook
Print element from the address book entry regarding the user's choice
inData is passed by reference (in/out)
*/
void PrintAddressBook(entryType s[],int bookSize)
{
    //entryType userRecord;
    char choice;

    cout << "Do you want to print a brief list? (Y/N)";
    cin >> choice;
    cout << endl; // space after ? for clean looking output.
    choice = toupper(choice);

    int i=0;
    if (choice == 'N') {
         //Loop through all records in the file
        while (i < bookSize){
        //        if (DebugP){
         //         cout << "Debug-PrintAddressBook-#1" << endl;
         //       }
            PrintRecord(s, i);
            i++;
        }
    }

    else {
        while (i < bookSize){
     //           if (DebugP){
      //              cout << "Debug-PrintAddressBook-#2" << endl;
     //           }
            PrintBriefRecord(s, i);
            i++;
        }
    }
}


/* PrintRecord
 Given all the elements of an address book entry, print the results
 userRecord is passed by value (in)
*/
void PrintRecord(entryType s[], int i)
{

    cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */s[i].name.firstName << " " << s[i].name.lastName << endl;

    cout << "Phone: " << "(" << s[i].phone.areaCode << ") "
                      << s[i].phone.prefix << "-"
                      << s[i].phone.number << endl;

    cout << "Address: " << s[i].address.street << " "
                        << s[i].address.city
                        << s[i].address.state << " "
                        << s[i].address.zip << endl;

    cout << "Social Media: " << "Email= " << s[i].socialmedia.email << " "
                             << "Facebook= " << s[i].socialmedia.facebook << " "
                             << "Twitter= " << s[i].socialmedia.twitter << endl << endl;


}

/* PrintBriefRecord
 Print name and Social Media data
 userRecord is passed by value (in)
 */

void PrintBriefRecord(entryType s[], int i)
{
    cout << "Name: " << /*GetTitle(userRecord.name.title) << ". "
                     << */s[i].name.firstName << " " << s[i].name.lastName << endl
                     << endl; // space after record output;

    cout << "Social Media: " << "Email= " << s[i].socialmedia.email << " "
                             << "Facebook= " << s[i].socialmedia.facebook << " "
                             << "Twitter= " << s[i].socialmedia.twitter << endl << endl;
    //Jason Creek - Social Media****
}

