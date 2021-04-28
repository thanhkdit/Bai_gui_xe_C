#include "San_oto.h"
void San_oto::Tong_so_cho() {
	Nhap_ds_slot();
	So_cho_oto = Ds_slot.size();
	cout << "\t- Tong so cho oto: " << So_cho_oto << endl;
}

void San_oto::So_cho_trong() {
	fstream f;
	string s;
	int n = 0;

	f.open("So_xe_vao_oto.txt", ios::in);
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

	Cho_trong_oto = So_cho_oto - n / 10;
	cout << "\t- So cho trong oto: " << Cho_trong_oto << endl;
}

void San_oto::Nhap_ds_slot() {
	Slot* temp = new Slot;
	int n = 1, a = 0; // a: tra ve -1 khi doc het du lieu tu file

	do
	{
		temp->Nhap(n, a);
		n++;
		if (a != -1)
			Ds_slot.push_back(temp);
		if (a == -1) // Doc het file
		{
			break;
		}
	} while (true);
}

San_oto::San_oto() {

}

San_oto::~San_oto() {

}