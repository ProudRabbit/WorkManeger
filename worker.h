#pragma once
#include <iostream>
#include<string>

using namespace std;

//ְ��������
class worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptname() = 0;


	int m_ID;	//ְ�����
	string m_name;	//ְ������
	int m_DeptID;	//ְ�����ڸ�λID
};

//Ա����
class Employee :public worker
{
public:
	Employee(int ID, string name, int DeptID);
	void showInfo();
	string getDeptname();

};

//������
class Manager :public worker
{
public:
	Manager(int ID, string name, int DeptID);
	void showInfo();
	string getDeptname();

};

//�ϰ���

class Boss :public worker
{
public:
	Boss(int ID, string name, int DeptID);
	void showInfo();
	string getDeptname();

};