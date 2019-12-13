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

	//统计文件中的人物数量
	int getEmpNum();

	void init_Emp();

	void showEmp();

	void delEmp();

	void changeEmp();

	void findEmp();

	//排序
	void sortEmp();

	void cleanEmp();

	//记录员工数量
	int m_EmpNum;

	//职工数组指针
	worker** m_EmpArray;

	bool m_FileIsEmpty;

	~workmanege();

};