#pragma once
#include "The.h"

class The_xe_may : public The
{
private:
	float Gia_xe_may;
public:
	void Lay_gia_xe_may();
	void Nhap_xe_may();
	void Xuat_xe_may();
	void Xoa_tt_xe_may(string);
	void Tim_kiem_xe();
	void Xoa_so_xe_ra();
	The_xe_may();
	~The_xe_may();
};