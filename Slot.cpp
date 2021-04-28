#include "Slot.h"

string Slot::Lay_ten_slot(string id_the) {

	fstream f;
	string str[50];
	int n = 0;
	f.open("The_oto.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, str[n], '|');
		n++;
	}
	n--;
	
	// Xoa ky tu xuong dong
	for (int j = 0; j < n; j++)
	{
		if (j != 0 && j % 2 == 0)
		{
			str[j].erase(0, 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == id_the)
			Ten_slot = str[i + 1];
	}
	return Ten_slot;
}

void Slot::Nhap(int n, int &a) {
	fstream f;
	string str[2];

	f.open("The_oto.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			getline(f, str[0], '|');
			getline(f, str[1], '|');
		}
		if (f.eof())
		{
			a = -1;
			return;
		}
		f.close();

		// Xoa ky tu xuong dong
		if (n > 1)
		{
			str[0].erase(0, 1);
		}

		Id_slot = str[0];
		Ten_slot = str[1];
	}
}

Slot::Slot() {

}

Slot::~Slot() {

}