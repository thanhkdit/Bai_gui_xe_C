#include "Bai_xe.h"

void Bai_xe::Cong_ty() {
	Ten_cong_ty = "----------------- BAI GUI XE DDTT -------------------";
	Dia_chi = "So 55 Giai Phong, Dong Tam, Hai Ba Trung, Ha Noi";
	cout << Ten_cong_ty << endl;
	cout << Dia_chi << endl << endl;
}

void Bai_xe::Menu(int &a, int &b) {
	string choice;
	bool check = false;
	if (a == 1) // Menu nhan vien
	{
		do
		{
			cout << "----------------------------------------------------------------\n";
			cout << "\n-----> Nhap lua chon: "; cin >> choice;
			if (choice == "1") //Nhap oto
			{
				The_xe = new The_oto;
				The_xe->Nhap_oto(); 
				break;
			}
			else if (choice == "2") //Xuat oto
			{
				The_xe = new The_oto;
				The_xe->Xuat_oto();
				break;
			}
			else if (choice == "3") //Nhap xe may
			{
				The_xe = new The_xe_may;
				The_xe->Nhap_xe_may();
				break;
			}
			else if (choice == "4") //Xuat xe may
			{
				The_xe = new The_xe_may;
				The_xe->Xuat_xe_may();
				break;
			}
			else if (choice == "5") //Tim kiem xe
			{
				string luachon;
				do
				{
					cout << "\n1. Tim kiem oto\n";
					cout << "2. Tim kiem xe may\n";
					cout << "0. Tro ve\n";
					cout << "\t+ Nhap lua chon: ";
					cin >> luachon;
					if (luachon == "1")
					{
						The_xe = new The_oto;
						The_xe->Tim_kiem_xe();
						break;
					}
					else if (luachon == "2")
					{
						The_xe = new The_xe_may;
						The_xe->Tim_kiem_xe();
						break;
					}
					else if (luachon == "0")
					{
						break;
					}
				} while (true);
				break;
			}
			else if (choice == "6") //Doi mat khau
			{
				b = 6;
				break;
			}
			else if (choice == "7") //Xem tt ca nhan
			{
				b = 7;
				break;
			}
			else if (choice == "8") //Thong ke
			{
				b = 8;
				break;
			}
			else if (choice == "9") //Xem tt nhan vien
			{
				b = 9;
				break;
			}
			else if (choice == "0") //Dang xuat
			{
				a = 0;
				break;
			}
		} while (true);
	}
	else if (a == 2) // Menu quan tri
	{
		do
		{
			cout << "----------------------------------------------------------------\n";
			cout << "\n-----> Nhap lua chon: "; cin >> choice;
			if (choice == "1") // Nhap oto
			{
				The_xe = new The_oto;
				The_xe->Nhap_oto();
				break;
			}
			else if (choice == "2") // Xuat oto
			{
				The_xe = new The_oto;
				The_xe->Xuat_oto();

				break;
			}
			else if (choice == "3")  // Nhap xe may
			{
				The_xe = new The_xe_may;
				The_xe->Nhap_xe_may();
				break;
			}
			else if (choice == "4") // Xuat xe may
			{
				The_xe = new The_xe_may;
				The_xe->Xuat_xe_may();
				break;
			}
			else if (choice == "5") //Tim kiem xe
			{
				string luachon;
				do
				{
					cout << "\n1. Tim kiem oto\n";
					cout << "2. Tim kiem xe may\n";
					cout << "0. Tro ve\n";
					cout << "\t+ Nhap lua chon: ";
					cin >> luachon;
					if (luachon == "1")
					{
						The_xe = new The_oto;
						The_xe->Tim_kiem_xe();
						break;
					}
					else if (luachon == "2")
					{
						The_xe = new The_xe_may;
						The_xe->Tim_kiem_xe();
						break;
					}
					else if (luachon == "0")
					{
						break;
					}
				} while (true);
				break;
			}
			else if (choice == "6") // Doi mat khau
			{
				b = 6;
				break;
			}
			else if (choice == "7") // Xem tt ca nhan
			{
				b = 7;
				break;
			}
			else if (choice == "8") // Xem tt nhan vien
			{
				b = 8;
				break;
			}
			else if (choice == "9") //Them the
			{
				Them_the();
				break;
			}
			else if (choice == "10") //Xoa the
			{
				Xoa_the();
				break;
			}
			else if (choice == "11") // Xoa so xe ra
			{
				string luachon1;
				cout << "\n1. Xoa thong tin trong so xe ra cua oto\n";
				cout << "2. Xoa thong tin trong so xe ra cua xe may\n";
				do
				{
					cout << "\t+ (0. Thoat) Nhap lua chon: "; cin >> luachon1;
					if (luachon1 == "1")
					{
						The_xe = new The_oto;
						The_xe->Xoa_so_xe_ra();
						break;
					}
					else if (luachon1 == "2")
					{
						The_xe = new The_xe_may;
						The_xe->Xoa_so_xe_ra();
						break;
					}
					else if (luachon1 == "0")
						return;
				} while (true);
				break;
			}
			else if (choice == "12") //Thong ke
			{
				b = 12;
				break;
			}
			else if (choice == "13")
			{
				Thay_doi_gia_tien();
				break;
			}
			else if (choice == "0") //Dang xuat
			{
				a = 0;
				break;
			}
		} while (true);
	}
}

void Bai_xe::Them_the() {
	fstream f;
	string str[100], id_them, vitri;
	int n = 0;
	bool check = false;
	string choice;
	do
	{
		cout << "\n\n1. Them the oto\t\t2. Them the xe may\t\t0. Ve menu\n";
		cout << "+ THEM THE: Nhap lua chon: ";
		cin >> choice;
		if (choice == "1") // Them the oto
		{
			f.open("The_oto.txt", ios::in);
			if (!f.is_open())
			{
				cout << "Khong the mo file!\n";
				system("pause");
				break;
			}
			else
			{
				while (!f.eof())
				{
					getline(f, str[n], '|');
					n++;
				}
				n--;
				f.close();
				// Xoa ky tu xuong dong
				for (int i = 0; i < n; i++)
				{
					if (i != 0 && i % 2 == 0)
					{
						str[i].erase(0, 1);
					}
				}

				// Them id the
				do
				{
					cout << "\n\n+++ (0. Tro ve) Nhap id the can them (OTO....): ";
					cin >> id_them;
					cout << "+++ (0. Tro ve) Nhap vi tri cua the (A->Z): ";
					cin >> vitri;
					if (id_them == "0" || vitri == "0")
						break;
					for (int i = 0; i < n; i++)
					{
						if (id_them == str[i] || vitri == str[i])
						{
							cout << "Id hoac vi tri da ton tai! ---> Vui long nhap lai!\n\n";
							break;
						}
						else if (i == n - 1)
						{
							f.open("The_oto.txt", ios::out | ios::app);
							if (!f.is_open())
							{
								cout << "Khong the mo file!\n";
								system("pause");
							}
							else
							{
								f << endl;
								f << id_them << "|" << vitri << "|";
								f.close();
								check = true;
								cout << "------ Da luu thong tin the! -------\n";
							}
							break;
						}
					}
					if (check == true)
						break;
				} while (true);
			}
		}
		else if (choice == "2") // Them the xe may
		{
			f.open("The_xe_may.txt", ios::in);
			if (!f.is_open())
			{
				cout << "Khong the mo file!\n";
				system("pause");
				break;
			}
			else
			{
				while (!f.eof())
				{
					getline(f, str[n], '|');
					n++;
				}
				n--;
				f.close();
				// Xoa ky tu xuong dong
				for (int i = 0; i < n; i++)
				{
					if (i != 0)
					{
						str[i].erase(0, 1);
					}
				}

				// Them the
				do
				{
					cout << "\n+++ (0. Tro ve) Nhap id the can them (XM....): ";
					cin >> id_them;
					if (id_them == "0")
						break;
					for (int i = 0; i < n; i++)
					{
						if (id_them == str[i])
						{
							cout << "Id da ton tai! ---> Vui long nhap lai!\n\n";
							break;
						}
						else if (i == n - 1)
						{
							f.open("The_xe_may.txt", ios::out | ios::app);
							if (!f.is_open())
							{
								cout << "Khong the mo file!\n";
								system("pause");
							}
							else
							{
								f << endl;
								f << id_them << "|";
								f.close();
								check = true;
								cout << "------ Da luu thong tin the! -------\n";
							}
							break;
						}
					}
					if (check == true)
						break;
				} while (true);
			}
		}
		else if (choice == "0")
		{
			system("pause");
			break;
		}
	} while (true);
}

void Bai_xe::Xoa_the() {
	fstream f;
	string str[100], thongtinxoa;
	int n;
	bool check = false;
	string choice;
	
	do
	{
		n = 0;
		cout << "\n\n1. Xoa the oto\t\t2. Xoa the xe may\t\t0. Ve menu\n";
		cout << "\n\t+ Nhap lua chon: ";
		cin >> choice;
		if (choice == "1") // Xoa the oto
		{
			f.open("The_oto.txt", ios::in);
			if (!f.is_open())
			{
				cout << "Khong the mo file!\n";
				system("pause");
				break;
			}
			else
			{
				while (!f.eof())
				{
					getline(f, str[n], '|');
					n++;
				}
				n--;
				f.close();
				// Xoa ky tu xuong dong
				for (int i = 0; i < n; i++)
				{
					if (i != 0 && i % 2 == 0)
					{
						str[i].erase(0, 1);
					}
				}

				// Xoa the
				do
				{
					cout << "+++ (0. Tro ve) Nhap id the hoac vi tri oto muon xoa (OTO...) (A->Z): ";
					cin >> thongtinxoa;
					if (thongtinxoa == "0")
						break;
					for (int i = 0; i < n; i++)
					{
						if (thongtinxoa != str[i]) //Tim den vi tri can xoa
						{
							if (i == n - 1)
							{
								cout << "Id hoac vi tri khong ton tai! ---> Vui long nhap lai!\n";
								break;
							}
						}
						else if (thongtinxoa == str[i])
						{
							f.open("The_oto.txt", ios::out | ios::trunc);
							if (!f.is_open())
							{
								cout << "Khong the mo file!\n";
								system("pause");
								break;
							}
							else
							{
								if (i % 2 == 0)
								{
									for (int j = 0; j < n - i; j++)
									{
										str[i + j] = str[i + j + 2];
									}
									n = n - 2;
									for (int k = 0; k < n; k++)
									{
										if (k == 0 || k % 2 == 1)
										{
											f << str[k] << "|";
										}
										else
										{
											f << endl << str[k] << "|";
										}
									}
									f.close();
								}
								else if (i % 2 == 1) //Xoa theo vi tri
								{
									for (int j = 0; j < n - i + 1; j++)
									{
										str[i - 1 + j] = str[i - 1 + j + 2];
									}
									n = n - 2;
									for (int k = 0; k < n; k++)
									{
										if (k == 0 || k % 2 == 1)
										{
											f << str[k] << "|";
										}
										else
										{
											f << endl << str[k] << "|";
										}
									}
									f.close();
								}
								check = true;
								cout << "------ Da xoa thong tin the! -------\n";
								system("pause");
								break;
							}
						}
					}
					if (check == true)
						break;
				} while (true);
			}
		}
		else if (choice == "2") //Xoa the xe may
		{
			f.open("The_xe_may.txt", ios::in);
			if (!f.is_open())
			{
				cout << "Khong the mo file!\n";
				system("pause");
				break;
			}
			else
			{
				while (!f.eof())
				{
					getline(f, str[n], '|');
					n++;
				}
				n--;
				f.close();
				// Xoa ky tu xuong dong
				for (int i = 0; i < n; i++)
				{
					if (i != 0)
					{
						str[i].erase(0, 1);
					}
				}

				// Xoa id the
				do
				{
					cout << "+++ (0. Tro ve) Nhap id the can xoa (XM....): ";
					cin >> thongtinxoa;
					if (thongtinxoa == "0")
						break;
					for (int i = 0; i < n; i++)
					{
						if (thongtinxoa != str[i])
						{
							if (i == n - 1)
							{
								cout << "Id hoac vi tri khong ton tai! ---> Vui long nhap lai!\n";
								break;
							}
						}
						else if (thongtinxoa == str[i])
						{
							f.open("The_xe_may.txt", ios::out | ios::trunc);
							if (!f.is_open())
							{
								cout << "Khong the mo file!\n";
								system("pause");
							}
							else
							{
								for (int j = 0; j < n - i; j++)
								{
									str[i + j] = str[i + j + 1];
								}
								n--;
								for (int k = 0; k < n; k++)
								{
									if (k == 0)
									{
										f << str[k] << "|";
									}
									else
									{
										f << endl << str[k] << "|";
									}
								}
								f.close();
								check = true;
								cout << "------ Da xoa thong tin the! -------\n";
							}
							break;
						}
					}
					if (check == true)
						break;
				} while (true);
			}
		}
		else if (choice == "0") //Thoat
		{
			break;
		}
	} while (true);
}

void Bai_xe::Thay_doi_gia_tien() {
	fstream f;
	int n = 0, gia;
	string str[10], choice, luachon;

	cout << "\n1. Dieu chinh gia oto\n";
	cout << "2. Dieu chinh gia xe may\n";
	cout << "0. Thoat\n";
	do
	{
		cout << "\n--------> Nhap lua chon: ";
		cin >> choice;
		if (choice == "0")
		{
			return;
		}
		else if (choice == "1")
		{
			f.open("Gia_tien.txt", ios::in);
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

			cout << "\n\t+++ Nhap gia moi cho oto: ";
			cin >> gia;
			cout << "\n1. Luu thong tin thay doi\t\t2. Huy thong tin vua nhap\n";
			do
			{
				cout << "\n-----> Nhap lua chon: ";
				cin >> luachon;
				if (luachon == "1")
				{
					f.open("Gia_tien.txt", ios::out | ios::trunc);
					if (!f.is_open())
					{
						cout << "Khong the mo file!\n";
						system("pause");
					}
					else
					{
						f << gia << "|" << str[1] << "|";
						f.close();
					}
					cout << "\n=======> Da luu thong tin" << endl;
					system("pause");
					return;
				}
				else if (luachon == "2")
				{
					cout << "\n========> Da huy thong tin vua nhap" << endl;
					system("pause");
					return;
				}
			} while (true);	
		}
		else if (choice == "2")
		{
			f.open("Gia_tien.txt", ios::in);
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

			cout << "\n\t+++ Nhap gia moi cho xe may: ";
			cin >> gia;
			cout << "\n1. Luu thong tin thay doi\t\t2. Huy thong tin vua nhap\n";
			do
			{
				cout << "\n-----> Nhap lua chon: ";
				cin >> luachon;
				if (luachon == "1")
				{
					f.open("Gia_tien.txt", ios::out | ios::trunc);
					if (!f.is_open())
					{
						cout << "Khong the mo file!\n";
						system("pause");
					}
					else
					{
						f << str[0] << "|" << gia << "|";
						f.close();
					}
					cout << "\n=======> Da luu thong tin" << endl;
					system("pause");
					return;
				}
				else if (luachon == "2")
				{
					cout << "\n========> Da huy thong tin vua nhap" << endl;
					system("pause");
					return;
				}
			} while (true);
		}
	} while (true);
}

void Bai_xe::Tong_so_cho() {

}

void Bai_xe::So_cho_trong() {

}

Bai_xe::Bai_xe() {

}

Bai_xe::~Bai_xe() {

}