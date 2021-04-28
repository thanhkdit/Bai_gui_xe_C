#pragma once
#include "Tai_khoan.h"

class Nhan_vien : public Tai_khoan
{
public:
	void Dang_nhap(int&);
	void Doi_mk();
	void Xem_tt_ca_nhan();
	void Xem_tt_nhan_vien();
	void Menu();
	bool CheckNV(string, string);
	Nhan_vien();
	~Nhan_vien();
};