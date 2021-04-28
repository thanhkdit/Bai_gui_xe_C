#pragma once
#include "Bai_xe.h"
#include "Slot.h"

class San_oto : public Bai_xe
{
protected:
	vector<Slot*> Ds_slot;
	int So_cho_oto;
	int Cho_trong_oto;
public:
	void Nhap_ds_slot();
	void Tong_so_cho();
	void So_cho_trong();
	San_oto();
	~San_oto();
};

