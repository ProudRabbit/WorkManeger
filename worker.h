#pragma once
#include <iostream>
#include<string>

using namespace std;

//职工抽象类
class worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptname() = 0;


	int m_ID;	//职工编号
	string m_name;	//职工姓名
	int m_DeptID;	//职工所在岗位ID
};

//员工类
class Employee :public worker
{
public:
	Employee(int ID, string name, int DeptID);
	void showInfo();
	string getDeptname();

};

//经理类
class Manager :public worker
{
public:
	Manager(int ID, string name, int DeptID);
	void showInfo();
	string getDeptname();

};

//老板类

class Boss :public worker
{
public:
	Boss(int ID, string name, int DeptID);
	void showInfo();
	string getDeptname();

};