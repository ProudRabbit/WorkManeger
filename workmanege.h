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

	//��¼Ա������
	int m_EmpNum;

	//ְ������ָ��
	worker** m_EmpArray;

	~workmanege();

};