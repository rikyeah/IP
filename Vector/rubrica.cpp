#include"rubrica.h"

void add(PhoneBook & B, Contact_Str & C)
{

	cout << "Dimmi il nome   ";
	cin >> C.Name;
	cout << "Dimmi il cognome   ";
	cin >> C.Surname;
	cout << "Dimmi il numero   ";
	cin >> C.PhoneNumber;
	B.push_back(C);
};

void print(const PhoneBook & B)
{
	for (unsigned int i = 0; i < B.size(); ++i)
		cout << (B.at(i)).Name << "  " << (B.at(i)).
		    Surname << "  " << (B.at(i)).PhoneNumber << endl;
};

void sortSurnames(PhoneBook & B)
{
	Contact_Str temp;
	unsigned int pos_min;
	for (unsigned int i = 0; i < B.size() - 1; ++i) {
		pos_min = i;
		for (unsigned int j = i; j < B.size(); ++j) {
			if ((B.at(j)).Surname < (B.at(pos_min)).Surname)
				pos_min = j;
		}
		if (pos_min != i) {
			temp = B.at(i);
			B.at(i) = B.at(pos_min);
			B.at(pos_min) = temp;
		}
	}
};

int FindPos(const PhoneBook & B, const string & item)
{
	int inizio = 0;
	int fine = B.size() - 1;
	int mid = (inizio + fine) / 2;
	while (inizio <= fine) {
		mid = (inizio + fine) / 2;
		cout << "mid " << mid << " inizio " << inizio << " fine " <<
		    fine << endl;
		if (item == (B[mid].Surname)) {
			cout << " trovato " << B[mid].Surname <<
			    " in posizione " << mid << endl;
			return mid;
		}
		if (item > (B.at(mid)).Surname) {
			cout << "in mid c e " << B[mid].Surname << endl;
			inizio = mid + 1;
		}
		if (item < (B.at(mid)).Surname) {
			cout << "in mid c e " << B[mid].Surname << endl;
			fine = mid - 1;
		}
	}
	//se non trovo l elemento
	cout << "elemento non trovato" << endl;
	unsigned int i = 0;
	if (B[B.size() - 1].Surname < item)
		return B.size() - 1;
	while (i < B.size()) {
		if (item > B[i].Surname) {
			cout << B[i].Surname << " non va ancora bene e la i e "
			    << i << endl;
			++i;
		} else {
			return i - 1;
		}
	}
};

void shift_PhoneBook(PhoneBook & B, unsigned int pos)
{
	Contact_Str C = { "", "", 0 };	//contatto vuoto per fare spazio
	B.push_back(C);
	if (pos == 0) {
		Contact_Str temp = B[0];
		for (unsigned int j = B.size() - 2; j > 0; --j)
			B[j + 1] = B[j];
		B[1] = temp;
		B[0] = C;
		return;
	}
	//else
	for (unsigned int i = B.size() - 1; i >= pos; --i)
		B.at(i) = B.at(i - 1);
	B.at(pos) = C;
};

void add_ord(PhoneBook & B, Contact_Str & C)
{
	shift_PhoneBook(B, FindPos(B, C.Surname) + 1);
	B.at(FindPos(B, C.Surname)) = C;
};
