#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Slot
{
private:
	string Ten_slot;
	string Id_slot;
public:
	void Nhap(int, int&);
	string Lay_ten_slot(string);
	Slot();
	~Slot();
};