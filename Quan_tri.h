#pragma once
#include "Tai_khoan.h"

class Quan_tri: public Tai_khoan
{
public:
	void Dang_nhap(int&);
	void Doi_mk();
	void Xem_tt_nhan_vien(); // Tim kiem, sua thong tin; them, xoa tk
	void Xem_tt_ca_nhan(); // Sua thong tin
	void Xoa_the();
	void Them_the();
	void Them_tai_khoan();
	void Xoa_tai_khoan();
	void Sua_thong_tin_nv();
	void Menu();
	bool CheckQT(string, string);
	Quan_tri();
	~Quan_tri();
};

