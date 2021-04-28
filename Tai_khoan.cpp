#include "Tai_khoan.h"
#include "Nhan_vien.h"
#include "Quan_tri.h"

void Tai_khoan::Dang_nhap(int &a) {
	cout << "- Usename (0. Thoat): ";
	cin >> usename;
	cout << "- Password: ";
	cin >> password;
}

void Tai_khoan::Menu() {
	cout << "1. Nhap oto\n";
	cout << "2. Xuat oto\n";
	cout << "3. Nhap xe may\n";
	cout << "4. Xuat xe may\n";
	cout << "5. Tim kiem xe\n";
	cout << "6. Doi mat khau\n";
	cout << "7. Xem thong tin ca nhan\n";
}

void Tai_khoan::Doi_mk() {

}

void Tai_khoan::Xem_tt_ca_nhan() {

}

string Tai_khoan::Lay_usename() {
	return usename;
}

string Tai_khoan::usename;

void Tai_khoan::Xem_tt_nhan_vien() {

}

Tai_khoan::Tai_khoan() {

}
Tai_khoan::~Tai_khoan() {

}