#include "Bai_xe.h"
#include "San_oto.h"
#include "San_xe_may.h"
#include "The.h"
int main()
{
	Bai_xe* bai = new Bai_xe;
	The the;
	int chucvu; //0: Dang xuat | 1: Nhan vien | 2: Quan tri
	int chucnangtk;
	do
	{
		system("cls");
		bai->Cong_ty();
		the.Dang_nhap(chucvu);
		if (chucvu == 1)
		{
			do
			{
				chucnangtk = 0;
				system("cls");
				bai->Cong_ty();
				the.Menu(chucvu);
				bai = new San_oto;
				cout << "\t\t****** Oto *******\n";
				bai->Tong_so_cho();
				bai->So_cho_trong();
				bai = new San_xe_may;
				cout << "\t\t****** Xe may *******\n";
				bai->Tong_so_cho();
				bai->So_cho_trong();
				bai->Menu(chucvu,chucnangtk);
				the.Menu_taikhoan(chucvu, chucnangtk);
				if (chucvu == 0)
					break; // Dang xuat
			} while (true);
			
		}
		else if (chucvu == 2)
		{
			do
			{
				chucnangtk = 0;
				system("cls");
				bai->Cong_ty();
				the.Menu(chucvu);
				bai = new San_oto;
				cout << "\t\t****** Oto *******\n";
				bai->Tong_so_cho();
				bai->So_cho_trong();
				bai = new San_xe_may;
				cout << "\t\t****** Xe may *******\n";
				bai->Tong_so_cho();
				bai->So_cho_trong();
				bai->Menu(chucvu, chucnangtk);
				the.Menu_taikhoan(chucvu, chucnangtk);
				if (chucvu == 0)
					break; // Dang xuat
			} while (true);
		}
	} while (chucvu == 0);
	delete bai;
	system("pause");
	return 0;
}