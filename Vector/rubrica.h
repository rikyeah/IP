#ifndef rubrica_h
#define rubrica_h
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Contact_Str {
	string Name;
	string Surname;
	unsigned int PhoneNumber;
};

typedef vector < Contact_Str > PhoneBook;

void add(PhoneBook &, Contact_Str &);

void print(const PhoneBook &);

void sortSurnames(PhoneBook &);

int FindPos(const PhoneBook &, const string &);

void shift_PhoneBook(PhoneBook &, unsigned int);

void add_ord(PhoneBook &, Contact_Str &);

#endif
