#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "The.h"
#include "The_oto.h"
#include "The_xe_may.h"
using namespace std;

class Bai_xe
{
protected:
	string Ten_cong_ty;
	string Dia_chi;
	The* The_xe;
public:
	void Menu(int&, int&);
	void Cong_ty();
	void Them_the();
	void Xoa_the();
	void Thay_doi_gia_tien();
	virtual void Tong_so_cho();
	virtual void So_cho_trong();
	Bai_xe();
	~Bai_xe();
};