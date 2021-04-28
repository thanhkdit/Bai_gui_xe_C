#include "Nhan_vien.h"
#include <iomanip>

void Nhan_vien::Dang_nhap(int &a) {
	int dem = 0;
	do {
		Tai_khoan::Dang_nhap(a);
		if (usename == "0")
		{
			a = 0;
			break;
		}
		if (CheckNV(usename, password) == true)
		{
			cout << "Ban la Nhan Vien\n";
			a = 1;
			break;
		}
		else
		{
			cout << "\nSai ten dang nhap hoac mat khau\n";
			a = 0;
		}
	} while (true);

}

void Nhan_vien::Menu() {
	cout << "************ MENU CUA NHAN VIEN ************\n";
	Tai_khoan::Menu();
	cout << "8. Thong ke thong tin gui xe trong ngay\n";
	cout << "9. Xem thong tin nhan vien khac\n";
	cout << "0. Dang xuat\n";
}

bool Nhan_vien::CheckNV(string id1, string pass1) {
	string str[20];
	fstream f;
	int i = 0;

	f.open("AccountNV.txt", ios::in);
	// Ghi file vao str[i]
	if (!f.is_open())
		cout << "------- Khong the mo file f !" << endl;
	else while (!f.eof())
	{
		getline(f, str[i], '|');
		i++;
	}
	i--;

	// Xoa ky tu dau tien cua str[i] (ky tu \n)
	for (int j = 0; j < i; j++)
	{
		if (j > 0 && j % 2 == 0)
			str[j].erase(0, 1);
	}

	f.close();
	// Kiem tra mat khau vua nhap
	for (int j = 0; j < i; j++)
	{
		if ((j % 2 == 0) && (str[j] == id1) && (str[j + 1] == pass1))
			return true;
	}
	return false;
}

void Nhan_vien::Doi_mk(){
	fstream f, f1;
	string str[50], oldpass, newpass;
	int i = 0;
	bool check = false;
	f.open("AccountNV.txt", ios::in);
	// Ghi du lieu tu file vao str[i]
	if (!f.is_open()) {
		cout << "----------- Khong the mo file f !";
		system("pause");
	}
	else while (!f.eof()) {
		getline(f, str[i], '|');
		i++;
	}
	i--;
	// Xoa ky tu dau tien cua str[i] (ky tu \n)
	for (int j = 0; j < i; j++)
	{
		if (j != 0 && j % 2 == 0)
		{
			str[j].erase(0, 1);
		}
	}

	do
	{
		cout << "Nhap mat khau cu: ";
		cin >> oldpass;
		for (int j = 0; j < i; j++) {
			if ((j % 2 == 0) && (str[j] == usename) && (str[j + 1] == oldpass)) // Nhập lại mật khẩu cũ đã đúng
			{
				cout << "\n+ Nhap mat khau moi: ";
				cin >> newpass;
				cin.ignore();
				str[j + 1] = newpass;
				check = true;
			}
		}
		if (check == false)
			cout << "Nhap sai mat khau roi may! Nhap lai di!\n";
	} while (check == false);
	f.close();

	// Xoa het du lieu trong file va ghi str[i] vao file sau khi doi mat khau
	f1.open("AccountNV.txt", ios::out | ios::trunc);
	if (!f1.is_open()) {
		cout << "\n------------ Khong the mo file f1 !\n";
		system("pause");
	}
	else if (check == true) {
		for (int j = 0; j < i; j++)
		{
			// Điều kiện: Mỗi dòng lưu thông tin 1 tài khoản
			if (j != 0 && j % 2 == 0)
				f1 << endl << str[j] << "|";
			else if (j == 0 || j % 2 == 1)
				f1 << str[j] << "|";
		}
	}
	f1.close();
	
	cout << "\n==========> Da doi mat khau thanh cong!\n";
	system("pause");
}

void Nhan_vien::Xem_tt_ca_nhan() {
	fstream f;
	string str[20];
	f.open("Thong_tin_nhan_vien.txt", ios::in);
	int i = 0;
	// Ghi file vào str[i]
	if (!f.is_open())
	{
		cout << "---------- Khong the mo file f !";
		system("pause");
	}
	else while(!f.eof()) {
		getline(f, str[i], '|');
		i++;
	}
	f.close();
	i--;
	// Xoa ky tu dau tien (ky tu \n)  cua "str[i] ở mỗi đầu dòng"
	for (int j = 0; j < i; j++)
	{
		if (j > 0 && j % 5 == 0)
			str[j].erase(0, 1);
	}
	for (int j = 0; j < i; j++)
	{
		// Tìm đến dòng lưu thông tin của tài khoản đang đăng nhập
		if ((j % 5 == 0) && (str[j] == usename))
		{
			cout << "\n\t************ Thong tin ca nhan *************\n\n";
			cout << "+ Ten tai khoan: " << str[j] << endl;
			cout << "+ Ho ten: " << str[j + 1] << endl;
			cout << "+ Dia chi: " << str[j+2] << endl;
			cout << "+ Ngay vao lam: " << str[j + 3] << endl;
			cout << "+ So dien thoai: " << str[j + 4] << endl;
			system("pause");
			break;
		}
		if (j == i - 1)
		{
			cout << "\n=========> Khong co thong tin!\n";
			system("pause");
			break;
		}
	}
}

void Nhan_vien::Xem_tt_nhan_vien() {
	fstream f;
	string str[20];
	int i = 0, dem = 0;

	// Ghi file vào str[i]
	f.open("Thong_tin_nhan_vien.txt", ios::in);
	if (!f.is_open())
	{
		cout << "---------- Khong the mo file f !";
		system("pause");
	}
	else while (!f.eof()) {
		getline(f, str[i], '|');
		i++;
	}
	f.close();
	i--;
	// Xoa ky tu dau tien (ky tu \n)  cua "str[i] ở mỗi đầu dòng"
	for (int j = 0; j < i; j++)
	{
		if (j > 0 && j % 5 == 0)
			str[j].erase(0, 1);
	}
	cout << endl;

	//Hien thi dau --------
	for (int j = 0; j < 100; j++)
	{
		cout << "-";
	}
	cout << endl;

	//Hien thi thong tin nhan vien
	cout << setw(4) << "STT" << setw(8) << "Ten TK" << setw(15) << "Ho ten" << setw(28) << "Dia chi" << setw(28) << "Ngay vao lam" << setw(11) << "SDT" << endl;
	for (int j = 0; j < i; j = j + 5)
	{
		// Tìm đến dòng lưu thông tin của tài khoản vừa nhập và xuất
		cout << setw(3) << j / 5 + 1 // STT
			<< setw(7) << str[j] //Ten tk
			<< setw(20) << str[j + 1] //Ho ten
			<< setw(37) << str[j + 2] //Dia chi
			<< setw(14) << str[j + 3] //Ngay vao lam
			<< setw(16) << str[j + 4] << endl; //So dien thoai
	}

	//Hien thi dau --------
	for (int j = 0; j < 100; j++)
	{
		cout << "-";
	}

	cout << endl;
	system("pause");
}

Nhan_vien::Nhan_vien() {

}

Nhan_vien::~Nhan_vien() {

}