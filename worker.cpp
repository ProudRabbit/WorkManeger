#include "worker.h"

//员工
Employee::Employee(int ID, string name, int DeptID)
{
	m_ID = ID;
	m_name = name;
	m_DeptID = DeptID;
}

void Employee::showInfo()
{
	cout << "职工编号： " << m_ID
		<< " \t职工姓名： " << m_name
		<< " \t岗位：" << this->getDeptname()
		<< " \t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptname()
{
	return "员工";
}


//经理
Manager::Manager(int ID, string name, int DeptID)
{
	m_ID = ID;
	m_name = name;
	m_DeptID = DeptID;
}

void Manager::showInfo()
{
	cout << "职工编号： " << m_ID
		<< " \t职工姓名： " << m_name
		<< " \t岗位：" << this->getDeptname()
		<< " \t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDeptname()
{
	return "经理";
}


//老板
Boss::Boss(int ID, string name, int DeptID)
{
	m_ID = ID;
	m_name = name;
	m_DeptID = DeptID;
}

void Boss::showInfo()
{
	cout << "职工编号： " << m_ID
		<< " \t职工姓名： " << m_name
		<< " \t岗位：" << this->getDeptname()
		<< " \t岗位职责：管理公司所有事物" << endl;
}

string Boss::getDeptname()
{
	return "总裁";
}
