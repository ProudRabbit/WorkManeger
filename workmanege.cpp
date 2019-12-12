#include"workmanege.h"

workmanege::workmanege()
{
	m_EmpNum = 0;
	m_EmpArray = NULL;
}

workmanege::~workmanege()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}

void workmanege::showmenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workmanege::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void workmanege:: addEmp()
{
	cout << "请输入要添加的职工人数："<<endl;
	int addnum = 0;	//保存用户要添加的职工的人数
	cin >> addnum;

	if (addnum > 0)
	{
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addnum;	//新空间大小等于原来的人数加上新添加的人数。
		//开辟新空间

		worker** newspace = new worker* [newSize];
		
		//将原来的数据拷贝到新空间
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newspace[i] = m_EmpArray[i];
			}

		}
		//批量添加新数据
		for (int i = 0; i < addnum; i++)
		{
			int id;		//职工ID
			string name;	//姓名
			int dselect;	//部门编号

			cout << "请输入第" << i + 1 << "个职工的编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工的姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dselect;

			worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, dselect);
				break;
			case 2:
				worker = new Manager(id, name, dselect);
				break;
			case 3:
				worker = new Boss(id, name, dselect);
				break;
			default:
				break;
			}

			//将创建的职工信息保存到数组中
			newspace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] m_EmpArray;

		//记录新空间地址
		m_EmpArray = newspace;

		//更新员工信息
		m_EmpNum = newSize;

		cout << "成功添加"<<addnum<< "名员工。"<< endl;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}


void workmanege::save()
{
	ofstream ofs;

	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_ID << " " << m_EmpArray[i]->m_name << " " << m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}