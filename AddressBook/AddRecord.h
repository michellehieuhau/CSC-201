
#ifndef ADDRECORD_H
#define ADDRECORD_H

void AddEntry(std::ifstream&, std::string);
void WriteRecord(std::ofstream&, entryType);
void AddRecord(entryType&);
void NormalizeRecord(std::string&);

#endif
