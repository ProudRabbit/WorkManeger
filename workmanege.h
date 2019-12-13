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

	int isExist(int id);

	//ͳ���ļ��е���������
	int getEmpNum();

	void init_Emp();

	void showEmp();

	void delEmp();

	void changeEmp();

	void findEmp();

	//����
	void sortEmp();

	void cleanEmp();

	//��¼Ա������
	int m_EmpNum;

	//ְ������ָ��
	worker** m_EmpArray;

	bool m_FileIsEmpty;

	~workmanege();

};