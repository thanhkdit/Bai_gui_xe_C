#include "Quan_tri.h"
#include <iomanip>

void Quan_tri::Dang_nhap(int &a) {
	int dem = 0;
	do {
		Tai_khoan::Dang_nhap(a);
		if (usename == "0")
		{
			a = 0;
			break;
		}
		if (CheckQT(usename, password) == true)
		{
			cout << "Ban la Quan Tri\n";
			a = 2;
			break;
		}
		else
		{
			cout << "\nSai ten dang nhap hoac mat khau\n";
			a = 0;
		}
	} while (true);
}

bool Quan_tri::CheckQT(string id1, string pass1) {
	string str[20];
	fstream f;
	int i = 0;
	f.open("AccountQT.txt", ios::in);
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

void Quan_tri::Menu() {
	cout << "************ MENU CUA QUAN TRI ************\n";
	Tai_khoan::Menu();
	cout << "8. Xem thong tin nhan vien\n";
	cout << "9. Them the\n";
	cout << "10. Xoa the\n";
	cout << "11. Xoa so xe ra\n";
	cout << "12. Thong ke thong tin gui xe trong ngay\n";
	cout << "13. Dieu chinh gia tien\n";
	cout << "0. Dang xuat\n";
}

void Quan_tri::Doi_mk() {
	fstream f, f1;
	string str[50], oldpass, newpass;
	int i = 0;
	bool check = false;
	f.open("AccountQT.txt", ios::in);
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
		if (j > 0 && j % 2 == 0)
			str[j].erase(0, 1);
	}
	// Doi mat khau
	do
	{
		cout << "\nNhap mat khau cu: ";
		cin >> oldpass;
		for (int j = 0; j < i; j++)
		{
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
	f1.open("AccountQT.txt", ios::out | ios::trunc);
	if (!f1.is_open()) {
		cout << "\n------------ Khong the mo file f1 !\n";
		system("pause");
	}
	else if (check == true)
	{
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

void Quan_tri::Xem_tt_ca_nhan() {
	fstream f;
	string str[20];
	int n = 0;

	// Ghi file vào str[i]
	f.open("Thong_tin_quan_tri.txt", ios::in);
	if (!f.is_open())
	{
		cout << "---------- Khong the mo file f !";
		system("pause");
	}
	else while (!f.eof()) {
		getline(f, str[n], '|');
		n++;
	}
	f.close();
	n--;
	// Xoa ky tu dau tien (ky tu \n)  cua "str[i] ở mỗi đầu dòng"
	for (int j = 0; j < n; j++)
	{
		if (j > 0 && j % 5 == 0)
			str[j].erase(0, 1);
	}

	// Thong tin ca nhan
	for (int j = 0; j < n; j++)
	{
		// Tìm đến dòng lưu thông tin của tài khoản vừa nhập và xuất
		if ((j % 5 == 0) && (str[j] == usename))
		{
			cout << "\n*************** Thong tin ca nhan **************\n\n";
			cout << "+ Ten tai khoan: " << str[j] << endl;
			cout << "+ Ho ten: " << str[j + 1] << endl;
			cout << "+ Dia chi: " << str[j + 2] << endl;
			cout << "+ Ngay vao lam: " << str[j + 3] << endl;
			cout << "+ So dien thoai: " << str[j + 4] << endl;
		}
	}

	string tentk, hoten, quequan, sdt, ngayvaolam;

	cout << "\n\n\t******* Menu xu ly *******\n";
	cout << "\n\t1. Sua ho ten\n";
	cout << "\t2. Sua ngay vao lam\n";
	cout << "\t3. Sua so dien thoai\n";
	cout << "\t4. Sua que quan\n";
	cout << "\t0. Thoat\n";

	string luachon;
	do
	{
		cout << "\n+ Nhap lua chon: "; cin >> luachon;
		if (luachon == "0")
		{
			return;
		}
		else if (luachon == "1")
		{
			cin.ignore();
			cout << "\n+++ Nhap ho ten moi: ";
			getline(cin, hoten);
			for (int j = 0; j < n; j++)
			{
				// Tìm đến dòng lưu thông tin của tài khoản vừa nhập và xuất
				if ((j % 5 == 0) && (str[j] == usename))
				{
					str[j + 1] = hoten;
				}
			}
			break;
		}
		else if (luachon == "2")
		{
			cin.ignore();
			cout << "\n+++ Nhap ngay vao lam sau khi sua: ";
			getline(cin, ngayvaolam);
			for (int j = 0; j < n; j++)
			{
				// Tìm đến dòng lưu thông tin của tài khoản vừa nhập và xuất
				if ((j % 5 == 0) && (str[j] == usename))
				{
					str[j + 3] = ngayvaolam;
				}
			}
			break;
		}
		else if (luachon == "3")
		{
			cout << "\n+++ Nhap so dien thoai moi: ";
			cin >> sdt;
			for (int j = 0; j < n; j++)
			{
				// Tìm đến dòng lưu thông tin của tài khoản vừa nhập và xuất
				if ((j % 5 == 0) && (str[j] == usename))
				{
					str[j + 4] = sdt;
				}
			}
			break;
		}
		else if (luachon == "4")
		{
			cin.ignore();
			cout << "\n+++ Nhap que quan sau khi sua: ";
			getline(cin, quequan);
			for (int j = 0; j < n; j++)
			{
				// Tìm đến dòng lưu thông tin của tài khoản vừa nhập và xuất
				if ((j % 5 == 0) && (str[j] == usename))
				{
					str[j + 2] = quequan;
				}
			}
			break;
		}
	} while (true);

	// Ghi thong tin sau khi sua vao file
	f.open("Thong_tin_quan_tri.txt", ios::out | ios::trunc);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0 || j % 5 != 0)
			{
				f << str[j] << "|";
			}
			else
			{
				f << endl << str[j] << "|";
			}
		}
	}
	cout << "\n================> Da luu thong tin\n";
	system("pause");
					
}

void Quan_tri::Xem_tt_nhan_vien() {
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
	cout << endl << endl;

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

	cout << "\n\n\t********Menu xu ly********\n";
	cout << "\t1. Them tai khoan nhan vien\n";
	cout << "\t2. Xoa tai khoan nhan vien\n";
	cout << "\t3. Sua thong tin nhan vien\n";
	cout << "\t0. Thoat\n";

	string choice;
	do
	{
		cout << "\n+ Nhap lua chon: "; cin >> choice;
		if (choice == "0")
			return;
		else if (choice == "1")
		{
			Them_tai_khoan();
			break;
		}
		else if (choice == "2")
		{
			Xoa_tai_khoan();
			break;
		}
		else if (choice == "3")
		{
			Sua_thong_tin_nv();
			break;
		}
	} while (true);
	
}

void Quan_tri::Them_tai_khoan() {
	fstream f;
	string tentk, mk;
	int k = 0, i = 0;
	string s[50],str[50];
	bool kt = false;

	// Ghi thong tin nhan vien
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

	// Xoa ky tu xuong dong
	for (int j = 0; j < i; j++)
	{
		if (j > 0 && j % 5 == 0)
			str[j].erase(0, 1);
	}

	// Ghi thong tin tai khoan
	f.open("AccountNV.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, s[k], '|');
		k++;
	}
	k--;
	f.close();

	// Xoa ky tu xuong dong
	for (int j = 0; j < k; j++)
	{
		if (j > 0 && j % 2 == 0)
			s[j].erase(0, 1);
	}

	// Them tai khoan
	do
	{
		cout << "+++ (0. Thoat) Nhap usename: "; cin >> tentk;

		for (int j = 0; j < k; j++)
		{
			if (j % 2 == 0 && s[j] == tentk)
			{
				break;
			}
			else if (j == k - 1)
			{
				cout << "\t+++ Nhap password: "; cin >> mk;
				s[k] = tentk;
				s[k + 1] = mk;
				k = k + 2;

				// Mo file va ghi du lieu moi vao
				f.open("AccountNV.txt", ios::out | ios::trunc);
				if (!f.is_open())
				{
					cout << "Khong the mo file!\n";
					system("pause");
				}
				else
				{
					for (int j = 0; j < k; j++)
					{
						if (j == 0 || j % 2 == 1)
						{
							f << s[j] << "|";
						}
						else if (j != 0 && j % 2 == 0)
						{
							f << endl << s[j] << "|";
						}
					}
					f.close();
				}

				// Nhap thong tin cho tai khoan moi
				f.open("Thong_tin_nhan_vien.txt", ios::out | ios::app);
				if (!f.is_open())
				{
					cout << "Khong the mo file!\n";
					system("pause");
				}
				else
				{
					string hoten, quequan, ngayvaolam, sdt;
					cin.ignore();
					cout << "\n\n\t********** Nhap thong tin cho tai khoan moi ***********\n";
					cout << "\n+ Ho ten nhan vien: "; getline(cin,hoten);
					cout << "+ Que quan: "; getline(cin, quequan);
					cout << "+ Ngay vao lam: "; getline(cin, ngayvaolam);
					cout << "+ So dien thoai: "; getline(cin, sdt);
					
					f << endl;
					f << tentk << "|";
					f << hoten << "|";
					f << quequan << "|";
					f << ngayvaolam << "|";
					f << sdt << "|";
					f.close();
				}
				kt = true;
				cout << "\n\n\t===========> Da luu thong tin!" << endl;
				break;
			}
		}
	} while (kt == false);	
	system("pause");
}

void Quan_tri::Xoa_tai_khoan() {
	fstream f;
	string choice, tentk, mk;
	int k = 0, i = 0;
	string s[50], str[50];
	bool kt = false;

	// Ghi thong tin nhan vien
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

	// Xoa ky tu xuong dong
	for (int j = 0; j < i; j++)
	{
		if (j > 0 && j % 5 == 0)
			str[j].erase(0, 1);
	}

	// Ghi thong tin tai khoan
	f.open("AccountNV.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, s[k], '|');
		k++;
	}
	k--;
	f.close();

	// Xoa ky tu xuong dong
	for (int j = 0; j < k; j++)
	{
		if (j > 0 && j % 2 == 0)
			s[j].erase(0, 1);
	}

	// Xoa tai khoan
	do
	{
		cout << "+++ (0. Thoat) Nhap ten tai khoan muon xoa: "; cin >> tentk;
		if (tentk == "0")
			return;
		for (int j = 0; j < k; j++)
		{
			if (s[j] == tentk)
			{
				// Xoa tai khoan
				for (int t = 0; t < k - j; t++)
				{
					s[j + t] = s[j + t + 2];
				}
				k = k - 2;

				// Luu danh sach tai khoan
				f.open("AccountNV.txt", ios::out | ios::trunc);
				if (!f.is_open())
				{
					cout << "Khong the mo file!\n";
					system("pause");
				}
				else
				{
					for (int t = 0; t < k; t++)
					{
						if (t == 0 || t % 2 == 1)
						{
							f << s[t] << "|";
						}
						else
						{
							f << endl << s[t] << "|";
						}
					}
					f.close();
				}

				// Xoa thong tin tai khoan
				for (int t = 0; t < i; t++)
				{
					if (str[t] == tentk)
					{
						for (int a = 0; a < i - t; a++)
						{
							str[t + a] = str[t + a + 5];
						}
						i = i - 5;
						break;
					}
				}

				// Luu thong tin tai khoan
				f.open("Thong_tin_nhan_vien.txt", ios::out | ios::trunc);
				if (!f.is_open())
				{
					cout << "Khong the mo file!\n";
					system("pause");
				}
				else
				{
					for (int t = 0; t < i; t++)
					{
						if (t == 0 || t % 5 != 0)
						{
							f << str[t] << "|";
						}
						else
						{
							f << endl << str[t] << "|";
						}
					}
					f.close();
				}
				kt = true;
				cout << "\n\t===========> Da luu thong tin!" << endl;
				break;
			}
		}
	} while (kt == false);
	system("pause");
}

void Quan_tri::Sua_thong_tin_nv() {
	fstream f;
	string tentk, hoten, quequan, sdt, ngayvaolam;
	int i = 0;
	string str[50];
	bool kt = false;

	// Ghi thong tin nhan vien
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

	// Xoa ky tu xuong dong
	for (int j = 0; j < i; j++)
	{
		if (j > 0 && j % 5 == 0)
			str[j].erase(0, 1);
	}

	cout << "\n\t************ Chinh sua thong tin nhan vien **************\n";
	do
	{
		cout << "\n+ Nhap ten tai khoan can sua: "; cin >> tentk;
		for (int j = 0; j < i; j++)
		{
			if (j % 5 == 0 && str[j] == tentk)
			{
				kt = true;
				cout << "\n1. Sua ho ten nhan vien\n";
				cout << "2. Sua ngay vao lam\n";
				cout << "3. Sua so dien thoai\n";
				cout << "4. Sua que quan\n";
				cout << "0. Thoat\n";

				string luachon;
				do
				{
					cout << "\n+ Nhap lua chon: "; cin >> luachon;
					if (luachon == "0")
					{
						return;
					}
					else if (luachon == "1")
					{
						cin.ignore();
						cout << "\n+++ Nhap ho ten moi: ";
						getline(cin, hoten);
						str[j + 1] = hoten;
						break;
					}
					else if (luachon == "2")
					{
						cin.ignore();
						cout << "\n+++ Nhap ngay vao lam sau khi sua: ";
						getline(cin, ngayvaolam);
						str[j + 3] = ngayvaolam;
						break;
					}
					else if (luachon == "3")
					{
						cout << "\n+++ Nhap so dien thoai moi: ";
						cin >> sdt;
						str[j + 4] = sdt;
						break;
					}
					else if (luachon == "4")
					{
						cin.ignore();
						cout << "\n+++ Nhap que quan sau khi sua: ";
						getline(cin, quequan);
						str[j + 2] = quequan;
						break;
					}
				} while (true);

				// Ghi thong tin sau khi sua vao file
				f.open("Thong_tin_nhan_vien.txt", ios::out | ios::trunc);
				if (!f.is_open())
				{
					cout << "Khong the mo file!\n";
					system("pause");
				}
				else
				{
					for (int j = 0; j < i; j++)
					{
						if (j == 0 || j % 5 != 0)
						{
							f << str[j] << "|";
						}
						else
						{
							f << endl << str[j] << "|";
						}
					}
				}
				cout << "\n================> Da luu thong tin\n";
				system("pause");
				break;
			}
		}
	} while (kt == false);
}

Quan_tri::Quan_tri() {

}

Quan_tri::~Quan_tri() {

}