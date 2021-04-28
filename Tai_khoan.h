#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tai_khoan
{
protected:
	static string usename;
	string password;
public:
	virtual void Dang_nhap(int&);
	virtual void Doi_mk();
	virtual void Menu();
	virtual void Xem_tt_ca_nhan();
	virtual void Xem_tt_nhan_vien();
	static string Lay_usename();
	Tai_khoan();
	~Tai_khoan();
};

