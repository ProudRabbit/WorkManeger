#include "worker.h"

//Ա��
Employee::Employee(int ID, string name, int DeptID)
{
	m_ID = ID;
	m_name = name;
	m_DeptID = DeptID;
}

void Employee::showInfo()
{
	cout << "ְ����ţ� " << m_ID
		<< " \tְ�������� " << m_name
		<< " \t��λ��" << this->getDeptname()
		<< " \t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptname()
{
	return "Ա��";
}


//����
Manager::Manager(int ID, string name, int DeptID)
{
	m_ID = ID;
	m_name = name;
	m_DeptID = DeptID;
}

void Manager::showInfo()
{
	cout << "ְ����ţ� " << m_ID
		<< " \tְ�������� " << m_name
		<< " \t��λ��" << this->getDeptname()
		<< " \t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDeptname()
{
	return "����";
}


//�ϰ�
Boss::Boss(int ID, string name, int DeptID)
{
	m_ID = ID;
	m_name = name;
	m_DeptID = DeptID;
}

void Boss::showInfo()
{
	cout << "ְ����ţ� " << m_ID
		<< " \tְ�������� " << m_name
		<< " \t��λ��" << this->getDeptname()
		<< " \t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptname()
{
	return "�ܲ�";
}
