#pragma once
#include <iostream>
#include "worker.h"
#include<fstream>

#define FILENAME "empFile.txt"

using namespace std;

class workmanege
{
public:
	workmanege();

	void showmenu();

	void exitsystem();

	void addEmp();

	void save();

	//记录员工数量
	int m_EmpNum;

	//职工数组指针
	worker** m_EmpArray;

	~workmanege();

};