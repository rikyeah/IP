#include"rubrica.h"

int main()
{
	PhoneBook pb;
	Contact_Str C;
	add(pb, C);
	add(pb, C);
	add(pb, C);
	add(pb, C);
	Contact_Str C1 = { "c", "c", 4 };
	sortSurnames(pb);
	add_ord(pb, C1);
	print(pb);

}
