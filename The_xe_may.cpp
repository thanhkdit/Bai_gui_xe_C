#include "The_xe_may.h"
#include <stdlib.h>
#include <ctime>

void The_xe_may::Lay_gia_xe_may() {
	fstream f;
	string str;

	f.open("Gia_tien.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!";
		system("pause");
	}
	else
	{
		getline(f, str, '|');
		getline(f, str, '|');
	}
	float a = atoi(str.c_str());
	Gia_xe_may = a;
}

void The_xe_may::Xoa_tt_xe_may(string id_xoa) {
	fstream f;
	string str[1000];
	int n = 0;

	f.open("So_xe_vao_xe_may.txt", ios::in);
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
	f.close();

	//Xoa ky tu xuong dong
	for (int i = 0; i < n; i++)
	{
		if (i % 9 == 0)
		{
			str[i].erase(0, 1);
		}
	}

	//Xoa thong tin oto
	for (int i = 0; i < n; i = i + 9)
	{
		if (str[i] == id_xoa)
		{
			for (int j = 0; j < n - i; j++)
				str[i + j] = str[i + j + 9];
			n = n - 9;
			break;
		}
	}

	//Ghi lai thong tin file
	f.open("So_xe_vao_xe_may.txt", ios::out | ios::trunc);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
	{
		for (int k = 0; k < n; k++)
		{
			if (k % 9 == 0)
			{
				f << endl << str[k] << "|";
			}
			else
			{
				f << str[k] << "|";
			}
		}
	}
	f.close();
}

void The_xe_may::Nhap_xe_may() {
	fstream f;
	string s1[100], s2[200];
	int n = 0, m = 0;

	cout << "\n\n\t\t--------------- Nhap xe may ---------------\n";
	The::Nhap_bai();

	// Danh sach the xe may

	f.open("The_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, s1[m], '|');
		if (m != 0)
			s1[m].erase(0, 1);
		m++;
	}
	m--;
	f.close();

	// Danh sach the da su dung
	f.open("So_xe_vao_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
	{
		getline(f, s2[n], '|');
		s2[n].erase(0, 1);
		n++;
		while (!f.eof())
		{
			for (int i = 0; i < 9; i++)
			{
				getline(f, s2[n], '|');
			}
			if (f.eof())
				break;
			s2[n].erase(0, 1);
			n++;
		}
	}
	f.close();

	//Xe nhap bai
	cout << "\n+ Tai khoan phu trach: " << Tai_khoan::Lay_usename() << endl;

	//Kiem tra id the co hop le khong?
	bool check = false, check2 = false;
	do
	{
		check = false;
		check2 = false;
		cout << "+ (0. Thoat) Nhap id the: "; cin >> id;
		if (id == "0")
			return;
		for (int i = 0; i < m; i++)
		{
			if (s1[i] == id)
				check = true;
		}
		for (int i = 0; i < n; i++)
		{
			if (s2[i] == id)
				check2 = true;
		}
		if (check == false)
		{
			cout << "\n\t======> Id the khong ton tai! Vui long nhap lai:\n";
		}
		else if (check2 == true)
		{
			cout << "\n\t======> Id the da duoc su dung! Vui long nhap lai:\n";
		}
	} while (check == false || check2 == true);
	cout << "+ Nhap bien so: "; cin >> Bien_so;
	cout << "\n1. Luu va thoat\t\t2. Huy du lieu vua nhap\n";
	string choice;
	
	do
	{
		cout << "- Nhap lua chon: ";
		cin >> choice;
		if (choice == "1")
		{
			f.open("So_xe_vao_xe_may.txt", ios::out | ios::app);
			f << endl << id << "|";
			f << Bien_so << "|";
			f << Gio_vao << "|";
			f << Phut_vao << "|";
			f << Giay_vao << "|";
			f << Ngay_vao << "|";
			f << Thang_vao << "|";
			f << Nam_vao << "|";
			f << Tai_khoan::Lay_usename() << "|";
			f.close();
			cout << "Da luu du lieu!\n";
			system("pause");
			break;
		}
		else if (choice == "2")
		{
			cout << "Da huy du lieu vua nhap!\n";
			system("pause");
			break;
		}
	} while (true);
	
}

void The_xe_may::Xuat_xe_may() {

	fstream f;
	string str[100], s[100];
	int n = 0, m = 0;
	int gio, ngayvao, thangvao, namvao, giovao, phutvao, songaytrongthang;
	string id_xuat, giayvao, tentk, bienso;
	bool check = false;

	cout << "\n\n\n--------------- Xuat xe may ---------------\n";
	f.open("So_xe_vao_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
	{
		getline(f, s[0], '|');
		s[0].erase(0, 1);
		m++;
		while (!f.eof())
		{
			for (int i = 0; i < 9; i++)
			{
				getline(f, s[m], '|');
			}
			if (f.eof())
				break;
			s[m].erase(0, 1);
			m++;
		}
		f.close();
	}

	do
	{
		cout << "+ (0. Thoat) Nhap id the ra: "; cin >> id;
		for (int i = 0; i < m; i++)
		{
			if (id == s[i])
			{
				check = true;
				break;
			}
			if (id == "0")
				return;
			if (i == m - 1)
				cout << "\n +++ Id vua nhap khong co trong bai! Vui long nhap lai!\n\n";
		}
	} while (check == false);

	f.open("So_xe_vao_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
		// Tim id va thong tin cua xe may khi gui xe
	{
		getline(f, str[0], '|');
		str[0].erase(0, 1);
		n++;
		while (!f.eof())
		{
			if (str[n - 1] == id)
			{
				for (int i = 0; i < 8; i++)
				{
					getline(f, str[n], '|');
					n++;
				}
				tentk = str[n - 1];
				namvao = atoi(str[n - 2].c_str());
				thangvao = atoi(str[n - 3].c_str());
				ngayvao = atoi(str[n - 4].c_str());
				giayvao = str[n - 5];
				phutvao = atoi(str[n - 6].c_str());
				giovao = atoi(str[n - 7].c_str());
				bienso = str[n - 8];
				id_xuat = str[n - 9];
				break;

			}

			// Luu id tiep theo vao str[n];
			for (int i = 0; i < 9; i++)
			{
				getline(f, str[n], '|');
				str[n].erase(0, 1);
			}
			n++;
		}
		n--;
	}
	f.close();

	// Tinh so ngay trong thang
	if (thangvao == 1 || thangvao == 3 || thangvao == 5 || thangvao == 7 || thangvao == 8 || thangvao == 10 || thangvao == 12)
	{
		songaytrongthang = 31;
	}
	else if (thangvao == 4 || thangvao == 6 || thangvao == 9 || thangvao == 11)
	{
		songaytrongthang = 30;
	}
	else if (thangvao == 2)
	{
		if (namvao % 4 == 0)
			songaytrongthang = 29;
		else if (namvao % 4 != 0)
			songaytrongthang = 28;
	}

	// Tinh tien
	int dem = 0; // dem so lan tinh tien
	for (int i = 0; i < n; i++)
	{
		if (str[i] == id)
		{
			cout << "+++++++++ Thoi gian nhap bai: " << endl;
			cout << "\t - Ngay " << ngayvao << " - " << thangvao << " - " << namvao << endl;
			cout << "\t - Luc " << giovao << ": " << phutvao << ": " << giayvao << endl << endl;
			The::Xuat_bai();
			// Tinh thoi gian gui
			if (Thang_ra == thangvao)
			{
				if (Ngay_ra == ngayvao)
				{
					gio = Gio_ra - giovao;
					if (gio < 8)
					{
						dem = 1;
					}
					else if (gio == 8)
					{
						if (Phut_ra > phutvao)
						{
							dem = 2;
						}
						else if (Phut_ra <= phutvao)
						{
							dem = 1;
						}
					}
					else if (gio > 8)
					{
						int x = gio % 8;
						int y = gio / 8;
						if (x == 0)
						{
							if (Phut_ra > phutvao)
							{
								dem = y + 1;
							}
							else if (Phut_ra <= phutvao)
							{
								dem = y;
							}
						}
						else if (x != 0)
						{
							dem = y + 1;
						}
					}
				}
				else if (Ngay_ra > ngayvao)
				{
					// Tinh tien trong ngay vao
					gio = 24 - giovao;
					if (gio < 8)
					{
						dem = 1;
					}
					else if (gio == 8)
					{
						dem = 2;
					}
					else if (gio > 8)
					{
						int x = gio % 8;
						int y = gio / 8;
						if (x == 0)
						{
							dem = y;
						}
						else if (x != 0)
						{
							dem = y + 1;
						}
					}

					// Tinh tien trong ngay ra
					gio = Gio_ra - 0;
					if (gio < 8)
					{
						dem = 1;
					}
					else if (gio == 8)
					{
						if (Phut_ra > phutvao)
						{
							dem = 2;
						}
						else if (Phut_ra = phutvao)
						{
							dem = 1;
						}
					}
					else if (gio > 8)
					{
						int x = gio % 8;
						int y = gio / 8;
						if (x == 0)
						{
							if (Phut_ra > phutvao)
							{
								dem = y + 1;
							}
							else if (Phut_ra = phutvao)
							{
								dem = y;
							}
						}
						else if (x != 0)
						{
							dem = y + 1;
						}
					}

					// Tinh tien trong nhung ngay o giua ngay vao va ngay ra
					if (Ngay_ra - ngayvao > 1)
					{
						int z = (Ngay_ra - ngayvao - 1);
						dem = dem + 3 * z;
					}
				}
			}
			else // Thang_ra > thangvao || Thang_ra < thangvao (Qua nam moi)
			{
				// Tinh tien trong ngay vao
				gio = 24 - giovao;
				if (gio < 8)
				{
					dem = 1;
				}
				else if (gio == 8)
				{
					dem = 2;
				}
				else if (gio > 8)
				{
					int x = gio % 8;
					int y = gio / 8;
					if (x == 0) // Gui trong 8h 16h 24h
					{
						dem = y;
					}
					else if (x != 0)
					{
						dem = y + 1;
					}
				}

				// Tinh tien trong ngay ra
				gio = Gio_ra - 0;
				if (gio < 8)
				{
					dem = dem + 1;
				}
				else if (gio == 8)
				{
					if (Phut_ra > phutvao)
					{
						dem = dem + 2;
					}
					else if (Phut_ra = phutvao)
					{
						dem = dem + 1;
					}
				}
				else if (gio > 8)
				{
					int x = gio % 8;
					int y = gio / 8;
					if (x == 0)
					{
						if (Phut_ra > phutvao)
						{
							dem = dem + y + 1;
						}
						else if (Phut_ra = phutvao)
						{
							dem = dem + y;
						}
					}
					else if (x != 0)
					{
						dem = dem + y + 1;
					}
				}

				// Tinh tien trong nhung ngay o giua ngay vao va ngay ra
				int z = (songaytrongthang - ngayvao + Ngay_ra + 1 - 2);
				dem = dem + 3 * z;

			}

			// Tong tien gui xe
			float thanhtien;
			Lay_gia_xe_may();
			thanhtien = dem * Gia_xe_may;
			cout << "======> Tong gia tien gui xe la: " << (size_t)thanhtien << endl;
			cout << "\n1. Luu va thoat\t\t2. Huy du lieu vua nhap\n";
			string luachon;
			do
			{
				cout << "--- Nhap lua chon: "; cin >> luachon;
				if (luachon == "1")
				{
					f.open("So_xe_ra_xe_may.txt", ios::out | ios::app);
					if (!f.is_open())
					{
						cout << "Khong the mo file!\n";
						system("pause");
					}
					else
					{
						f << endl;
						f << id_xuat << "|";
						f << bienso << "|";
						f << giovao << "|";
						f << phutvao << "|";
						f << giayvao << "|";
						f << ngayvao << "|";
						f << thangvao << "|";
						f << namvao << "|";
						f << Gio_ra << "|";
						f << Phut_ra << "|";
						f << Giay_ra << "|";
						f << Ngay_ra << "|";
						f << Thang_ra << "|";
						f << Nam_ra << "|";
						f << thanhtien << "|";
						f << tentk << "|";
						f.close();
					}
					Xoa_tt_xe_may(id);
					cout << "Da luu du lieu!\n";
					system("pause");
					break;
				}
				else if (luachon == "2")
				{
					cout << "Da huy du lieu vua nhap!\n";
					system("pause");
					break;
				}
			} while (true);
		}
	}
}

void The_xe_may::Tim_kiem_xe() {
	fstream f;
	string str[100], s[100], str1[100], s1[100];
	int n = 0, m = 0, x = 0, y = 0;
	string tt_tim_kiem;
	time_t hientai = time(0);
	tm* pTime = localtime(&hientai);

	int ngayra = pTime->tm_mday;

	cout << "\n+ (0. Thoat) Nhap id hoac bien so xe muon tim kiem: ";
	cin >> tt_tim_kiem;
	if (tt_tim_kiem == "0")
		return;
	f.open("So_xe_vao_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
	{
		getline(f, str[n], '|');
		str[n].erase(0, 1);
		n++;
		getline(f, str[n], '|');
		n++;
		while (!f.eof())
		{
			for (int j = 0; j < 8; j++)
			{
				getline(f, str[n], '|');
			}
			if (f.eof())
				break;
			str[n].erase(0, 1);
			n++;
			getline(f, str[n], '|');
			n++;
		}
		f.close();
	}

	// Tim kiem xe co trong bai hay khong
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (tt_tim_kiem == str[i]) // Xe trong con trong bai
		{
			check = true;
		}
	}

	// Kiem tra bien so trong so xe ra xe may neu xe may khong co trong bai
	bool check2 = false;
	if (check == false)
	{
		f.open("So_xe_ra_xe_may.txt", ios::in);
		if (!f.is_open())
		{
			cout << "Khong the mo file!\n";
			system("pause");
		}
		else
		{
			getline(f, str1[x], '|');
			str1[x].erase(0, 1);
			x++;
			getline(f, str1[x], '|');
			x++;
			while (!f.eof())
			{
				for (int j = 0; j < 15; j++)
				{
					getline(f, str1[x], '|');
				}
				if (f.eof())
					break;
				str1[x].erase(0, 1);
				x++;
				getline(f, str1[x], '|');
				x++;
			}
			f.close();
		}

		for (int i = 0; i < x; i++)
		{
			if (tt_tim_kiem == str1[i]) // Xe khong con trong bai
			{
				check2 = true;
			}
		}
	}

	if (check == true) // Tim kiem xe trong bai
	{
		f.open("So_xe_vao_xe_may.txt", ios::in);
		if (!f.is_open())
		{
			cout << "Khong the mo file!\n";
			system("pause");
		}
		else
		{
			while (!f.eof())
			{
				getline(f, s[m], '|');
				s[m].erase(0, 1);
				getline(f, s[m + 1], '|');
				if (s[m] == tt_tim_kiem || s[m + 1] == tt_tim_kiem)
				{
					getline(f, s[m + 2], '|');
					getline(f, s[m + 3], '|');
					getline(f, s[m + 4], '|');
					getline(f, s[m + 5], '|');
					getline(f, s[m + 6], '|');
					getline(f, s[m + 7], '|');
					getline(f, s[m + 8], '|');

					cout << "\n\n************ Thong tin tim kiem ************\n";
					cout << "\n\n\t+ Id the: " << s[m] << endl;
					cout << "\t+ Bien so: " << s[m + 1] << endl;
					cout << "\t+ Thoi gian gui:\n";
					cout << "\t\t- Gio vao: " << s[m + 2] << " : " << s[m + 3] << " : " << s[m + 4] << endl;
					cout << "\t\t- Ngay vao: " << s[m + 5] << " - " << s[m + 6] << " - " << s[m + 7] << endl;
					cout << "\t+ Tai khoan phu trach: " << s[m + 8] << endl;
					cout << "\n=====> Da hien thi het thong tin\n";
					system("pause");
					f.close();
					break;
				}
				else
				{
					for (int j = 0; j < 7; j++)
					{
						getline(f, s[m], '|');
					}
				}
			}
		}
	}

	// Xe da xuat bai
	else if (check2 == true)
	{
		f.open("So_xe_ra_xe_may.txt", ios::in);
		if (!f.is_open())
		{
			cout << "Khong the mo file!\n";
			system("pause");
		}
		else
		{
			while (!f.eof())
			{
				getline(f, s1[y], '|');
				s1[y].erase(0, 1);
				getline(f, s1[y + 1], '|');
				if (f.eof())
					break;
				if (s1[y + 1] == tt_tim_kiem || s1[y] == tt_tim_kiem)
				{
					getline(f, s1[y + 2], '|');
					getline(f, s1[y + 3], '|');
					getline(f, s1[y + 4], '|');
					getline(f, s1[y + 5], '|');
					getline(f, s1[y + 6], '|');
					getline(f, s1[y + 7], '|');
					getline(f, s1[y + 8], '|');
					getline(f, s1[y + 9], '|');
					getline(f, s1[y + 10], '|');
					getline(f, s1[y + 11], '|');
					getline(f, s1[y + 12], '|');
					getline(f, s1[y + 13], '|');
					getline(f, s1[y + 14], '|');
					getline(f, s1[y + 15], '|');
					if (f.eof())
						cout << "Da o cuoi file\n";

					// In ra thong tin gui xe trong ngay
					int a = atoi(s1[y + 11].c_str());
					if (ngayra - a < 2)
					{
						cout << "\n\n************ Thong tin tim kiem ************\n";
						cout << "\n========> Xe da xuat bai!\n";
						cout << "\n\t+ Id the: " << s1[y] << endl;
						cout << "\t+ Bien so: " << s1[y + 1] << endl;
						cout << "\t+ Thoi gian gui:\n";
						cout << "\t\t- Gio vao: " << s1[y + 2] << " : " << s1[y + 3] << " : " << s1[y + 4] << endl;
						cout << "\t\t- Ngay vao: " << s1[y + 5] << " - " << s1[y + 6] << " - " << s1[y + 7] << endl;
						cout << "\n\t+ Thoi gian ra:\n";
						cout << "\t\t- Gio ra: " << s1[y + 8] << " : " << s1[y + 9] << " : " << s1[y + 10] << endl;
						cout << "\t\t- Ngay ra: " << s1[y + 11] << " - " << s1[y + 12] << " - " << s1[y + 13] << endl;
						cout << "\t- Thanh tien: " << s1[y + 14] << endl;
						cout << "\t- Tai khoan phu trach: " << s1[y + 15] << endl;
					}
				}
				else
				{
					for (int i = 0; i < 14; i++)
						getline(f, s1[y], '|');
				}
			}
			f.close();
			cout << "\n==========> Da hien thi het thong tin tim kiem!\n";
			system("pause");
		}
	}
	else
	{
		cout << "\n========> Khong tim thay!\n";
		system("pause");
	}
}

void The_xe_may::Xoa_so_xe_ra() {
	fstream f;
	f.open("So_xe_ra_xe_may.txt",ios::out | ios::trunc);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else
	{
		cout << "\n\t===========> Da xoa thong tin trong so xe ra!\n";
		system("pause");
		f.close();
	}
}

The_xe_may::The_xe_may() {

}

The_xe_may::~The_xe_may() {

}