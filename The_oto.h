#pragma once
#include "The.h"
#include "Slot.h"

class The_oto : public The
{
private:
	Slot Vi_tri;
	float Gia_oto;
public:
	void Lay_gia_oto();
	void Nhap_oto();
	void Xuat_oto();
	void Xoa_tt_oto(string);
	void Tim_kiem_xe();
	void Xoa_so_xe_ra();
	The_oto();
	~The_oto();
};

