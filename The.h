#pragma once
#include <vector>
#include "Tai_khoan.h"
#include "Nhan_vien.h"
#include "Quan_tri.h"
using namespace std;

class The
{
protected:
	string id;
	string Bien_so;
	string Ten_tk;
	int Ngay_vao;
	int Thang_vao;
	int Nam_vao;
	int Gio_vao;
	int Phut_vao;
	int Giay_vao;
	int Ngay_ra;
	int Thang_ra;
	int Nam_ra;
	int Gio_ra;
	int Phut_ra;
	int Giay_ra;
	Tai_khoan* Tk_phu_trach;
public:
	void Menu(int);
	void Menu_taikhoan(int, int);
	void Dang_nhap(int &);
	void Nhap_bai();
	void Xuat_bai();
	void Thong_ke();
	virtual void Nhap_oto();
	virtual void Xuat_oto();
	virtual void Nhap_xe_may();
	virtual void Xuat_xe_may();
	virtual void Tim_kiem_xe();
	virtual void Xoa_so_xe_ra();
	The();
	~The();
};