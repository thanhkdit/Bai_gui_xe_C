#include "San_xe_may.h"
void San_xe_may::Tong_so_cho() {
	fstream f;
	string s;
	int n = 0;

	f.open("The_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, s, '|');
		n++;
	}
	n--;
	f.close();

	So_cho_xe_may = n;
	cout << "\t- Tong so cho xe may la: " << So_cho_xe_may << endl;
}

void San_xe_may::So_cho_trong() {
	fstream f;
	string s;
	int n = 0;

	f.open("So_xe_vao_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, s, '|');
		n++;
	}
	n--;
	f.close();

	Cho_trong_xe_may = So_cho_xe_may - n / 9;
	cout << "\t- So cho trong xe may la: " << Cho_trong_xe_may << endl;
}

San_xe_may::San_xe_may() {

}

San_xe_may::~San_xe_may() {

}