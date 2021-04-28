#pragma once
#include "Bai_xe.h"

class San_xe_may : public Bai_xe
{
private:
	int So_cho_xe_may;
	int Cho_trong_xe_may;
public:
	void Tong_so_cho();
	void So_cho_trong();
	San_xe_may();
	~San_xe_may();
};

