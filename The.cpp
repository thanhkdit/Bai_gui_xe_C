#include "The.h"
#include "The_oto.h"
#include "The_xe_may.h"
#include <ctime>
#include <iomanip>

void The::Dang_nhap(int &b) {
	string choice;
	bool check = false;
	cout << "****** Chon quyen dang nhap ********\n";
	cout << "1. Dang nhap voi quyen nhan vien\n";
	cout << "2. Dang nhap voi quyen quan tri\n";
	cout << "0. Thoat chuong trinh\n";
	do
	{
		cout << "+ Nhap lua chon cua ban: "; cin >> choice;
		if (choice == "1")
		{
			check = true;
			Tk_phu_trach = new Nhan_vien;
			Tk_phu_trach->Dang_nhap(b);
			Ten_tk = Tk_phu_trach->Lay_usename();
		}
		else if(choice == "2")
		{
			check = true;
			Tk_phu_trach = new Quan_tri;
			Tk_phu_trach->Dang_nhap(b);
			Ten_tk = Tk_phu_trach->Lay_usename();
		}
		else if (choice == "0")
		{
			exit(0);
		}
	} while (check == false);
	
}

void The::Menu(int a) {
	if (a == 1)
	{
		Tk_phu_trach = new Nhan_vien;
		Tk_phu_trach->Menu();
	}
	else if (a == 2)
	{
		Tk_phu_trach = new Quan_tri;
		Tk_phu_trach->Menu();
	}
}

void The::Menu_taikhoan(int b, int a) {
	if (b == 1) // Nhan vien
	{
		if (a == 6)
		{
			Tk_phu_trach = new Nhan_vien;
			Tk_phu_trach->Doi_mk();
		}
		else if (a == 7)
		{
			Tk_phu_trach = new Nhan_vien;
			Tk_phu_trach->Xem_tt_ca_nhan();
		}
		else if (a == 8)
		{
			Thong_ke();
		}
		else if (a == 9)
		{
			Tk_phu_trach = new Nhan_vien;
			Tk_phu_trach->Xem_tt_nhan_vien();
		}
	}
	else if (b == 2) // Quan tri
	{
		if (a == 6)
		{
			Tk_phu_trach = new Quan_tri;
			Tk_phu_trach->Doi_mk();
		}
		else if (a == 7)
		{
			Tk_phu_trach = new Quan_tri;
			Tk_phu_trach->Xem_tt_ca_nhan();
		}
		else if (a == 8)
		{
			Tk_phu_trach = new Quan_tri;
			Tk_phu_trach->Xem_tt_nhan_vien();
		}
		else if (a == 12)
		{
			Thong_ke();
		}
	}
}

void The::Nhap_bai() {

	time_t hientai = time(0);
	tm* pTime = localtime(&hientai);

	Ngay_vao = pTime->tm_mday;
	Thang_vao = 1 + pTime->tm_mon;
	Nam_vao = 1900 + pTime->tm_year;
	Gio_vao = pTime->tm_hour;
	Phut_vao = pTime->tm_min;
	Giay_vao = pTime->tm_sec;
	cout << "\n+ Thoi gian nhap bai: " << endl;
	cout << "\t - Ngay " << Ngay_vao << " - " << Thang_vao << " - " << Nam_vao << endl;
	cout << "\t - Luc " << Gio_vao << ": " << Phut_vao << ": " << Giay_vao << endl;

};

void The::Xuat_bai() {
	time_t hientai = time(0);
	tm* pTime = localtime(&hientai);

	Ngay_ra = pTime->tm_mday;
	Thang_ra = 1 + pTime->tm_mon;
	Nam_ra = 1900 + pTime->tm_year;
	Gio_ra = pTime->tm_hour;
	Phut_ra = pTime->tm_min;
	Giay_ra = pTime->tm_sec;

	cout << "+++++++++ Thoi gian xuat bai: " << endl;
	cout << "\t - Ngay " << Ngay_ra << " - " << Thang_ra << " - " << Nam_ra << endl;
	cout << "\t - Luc " << Gio_ra << ": " << Phut_ra << ": " << Giay_ra << endl;

}

void The::Thong_ke() {
	fstream f;
	string str1[1000], str2[1000], str3[1000], str4[1000];
	int n = 0, m = 0, k = 0, t = 0;
	bool check = false;

	time_t hientai = time(0);
	tm* pTime = localtime(&hientai);
	int ngay, thang;

	ngay = pTime->tm_mday;
	thang = 1 + pTime->tm_mon;

	f.open("So_xe_ra_oto.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, str1[n], '|');
		n++;
	}
	n--;
	f.close();

	f.open("So_xe_ra_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, str2[m], '|');
		m++;
	}
	m--;
	f.close();

	f.open("So_xe_vao_oto.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, str3[k], '|');
		k++;
	}
	k--;
	f.close();

	f.open("So_xe_vao_xe_may.txt", ios::in);
	if (!f.is_open())
	{
		cout << "Khong the mo file!\n";
		system("pause");
	}
	else while (!f.eof())
	{
		getline(f, str4[t], '|');
		t++;
	}
	t--;
	f.close();

	// Xuat ra man hinh
	cout << "\n==============> Xe da xuat bai trong ngay:\n";
	cout << "\n\t\t\t\tOTO\n";
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout << setw(4) << "Id" << setw(12) << "Bien so" << setw(8) << "Vi tri" << setw(12) << "Gio vao" << setw(17) << "Ngay vao" << setw(16) << "Gio ra" << setw(16) << "Ngay ra" << setw(16) << "Thanh tien" << setw(14) << "Tk phu trach" << endl;
	//Hien thi oto xuat bai trong ngay
	for (int i = 0; i < n; i++)
	{
		if (i % 17 == 12 && str1[i] == to_string(ngay) && str1[i+1] == to_string(thang)) //Vi tri luu tru thu 12 (ngay)
		{
			cout << str1[i - 12] //id
			     << setw(8) << str1[i - 11] //bien so
			     << setw(6) << str1[i - 10] //vi tri
			     << setw(17) << str1[i - 9] + " : " + str1[i - 8] + " : " + str1[i - 7] //gio vao
				 << setw(17) << str1[i - 6] + " - " + str1[i - 5] + " - " + str1[i - 4] //ngay vao
				 << setw(17) << str1[i - 3] + " : " + str1[i - 2] + " : " + str1[i - 1] //gio ra
				 << setw(17) << str1[i] + " - " + str1[i + 1] + " - " + str1[i + 2] //ngay ra
			  	 << setw(9) << str1[i + 3] //thanh tien
				 << setw(11) << str1[i + 4]; //Tk phu trach
		}
	}
	cout << endl;
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl << endl;

	cout << "\n\t\t\t\tXE MAY\n";
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout << setw(4) << "Id" << setw(11) << "Bien so" << setw(14) << "Gio vao" << setw(17) << "Ngay vao" << setw(16) << "Gio ra" << setw(16) << "Ngay ra" << setw(16) << "Thanh tien" << setw(14) << "Tk phu trach" << endl;
	// Hien thi xe may xuat bai trong ngay
	for (int i = 0; i < m; i++)
	{
		if (i % 16 == 11 && str2[i] == to_string(ngay) && str2[i + 1] == to_string(thang)) //Vi tri luu tru thu 11 (ngay)
		{
			cout << str2[i - 11] //id
				<< setw(8) << str2[i - 10] //bien so
				<< setw(17) << str2[i - 9] + " : " + str2[i - 8] + " : " + str2[i - 7] //gio vao
				<< setw(17) << str2[i - 6] + " - " + str2[i - 5] + " - " + str2[i - 4] //ngay vao
				<< setw(17) << str2[i - 3] + " : " + str2[i - 2] + " : " + str2[i - 1] //gio ra
				<< setw(17) << str2[i] + " - " + str2[i + 1] + " - " + str2[i + 2] //ngay ra
				<< setw(9) << str2[i + 3] //thanh tien
				<< setw(11) << str2[i + 4]; //Tk phu trach
		}
	}
	cout << endl;
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl << endl;

	cout << "\n===========> Xe con trong bai:\n";
	cout << "\n\t\t\tOTO\n";
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout << setw(4) << "Id" << setw(12) << "Bien so" << setw(8) << "Vi tri" << setw(12) << "Gio vao" << setw(17) << "Ngay vao" << setw(17) << "Tk phu trach" << endl;
	for (int i = 0; i < k; i = i + 10)
	{
		cout << str3[i] //id
			<< setw(8) << str3[i + 1] //bien so
			<< setw(6) << str3[i + 2] //vi tri
			<< setw(17) << str3[i + 3] + " : " + str3[i + 4] + " : " + str3[i + 5] //gio vao
			<< setw(17) << str3[i + 6] + " - " + str3[i + 7] + " - " + str3[i + 8] //ngay vao
			<< setw(10) << str3[i + 9]; //Tk phu trach
	}
	cout << endl;
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl << endl;

	cout << "\n\t\t\tXE MAY\n";
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout << setw(4) << "Id" << setw(12) << "Bien so" << setw(12) << "Gio vao" << setw(17) << "Ngay vao" << setw(18) << "Tk phu trach" << endl;
	for (int i = 0; i < t; i = i + 9)
	{
		cout << str4[i] //id
			<< setw(8) << str4[i + 1] //bien so
			<< setw(17) << str4[i + 2] + " : " + str4[i + 3] + " : " + str4[i + 4] //gio vao
			<< setw(17) << str4[i + 5] + " - " + str4[i + 6] + " - " + str4[i + 7] //ngay vao
			<< setw(10) << str4[i + 8]; //Tk phu trach
	}
	cout << endl;
	//Hien thi dau ------------
	for (int i = 0; i < 115; i++)
	{
		cout << "_";
	}
	cout << endl << endl;

	string choice;
	cout << "1. Thong ke tien\n";
	cout << "2. Thoat ra\n";
	do
	{
		cout << "\t- Nhap lua chon: "; cin >> choice;
		if (choice == "1")
		{
			
			// Tinh tien
			float a, b, tongtien1 = 0, tongtien2 = 0;
			for (int i = 0; i < n; i++)
			{
				if (i % 17 == 12 && str1[i] == to_string(ngay) && str1[i + 1] == to_string(thang))
				{
					a = atoi(str1[i + 3].c_str());
					tongtien1 += a;
				}
			}
			for (int i = 0; i < m; i++)
			{
				if (i % 16 == 11 && str2[i] == to_string(ngay) && str2[i + 1] == to_string(thang))
				{
					b = atoi(str2[i + 3].c_str());
					tongtien2 += b;
				}
			}
			cout << "\n\n- Tong tien thu duoc trong ngay tu oto la: " << tongtien1;
			cout << "\n- Tong tien thu duoc trong ngay tu xe may la: " << tongtien2;
			cout << "\n\n===> Tong tien thu duoc trong ngay la: " << (size_t)(tongtien1 + tongtien2) << endl << endl;
			system("pause");
			break;
		}
		if (choice == "2")
		{
			system("pause");
			break;
		}
	} while (true);
	
}

void The::Tim_kiem_xe() {

}

void The::Nhap_oto() {

};

void The::Xuat_oto() {

};

void The::Nhap_xe_may() {

};

void The::Xuat_xe_may() {

};



void The::Xoa_so_xe_ra() {

}

The::The() {

}

The::~The() {

}