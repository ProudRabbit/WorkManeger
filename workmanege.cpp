#include"workmanege.h"

workmanege::workmanege()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//读文件

	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在。" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	//文件为空
	if (ifs.eof())
	{
		cout << "文件为空。" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在
	int num = getEmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new worker * [this->m_EmpNum];	//开辟空间
	this->init_Emp();		//将文件读取到开辟的堆区空间

}

workmanege::~workmanege()
{
	if (m_EmpArray != NULL)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i] != NULL)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
		}
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

		//更新文件不为空标志
		m_FileIsEmpty = false;

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

int workmanege::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int Did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		num++;
	}
	return num;
}

void workmanege::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int Did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		worker* work = NULL;
		if (Did == 1)
		{
			work = new Employee(id, name, Did);
		}
		else if (Did == 2)
		{
			work = new Manager(id, name, Did);
		}
		else if (Did == 3)
		{
			work = new Boss(id, name, Did);
		}
		this->m_EmpArray[index] = work;
		index++;
	}
	ifs.close();
}

void workmanege::showEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空。" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int workmanege::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workmanege::delEmp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在且记录为空。" << endl;
	}
	else
	{
		cout << "请输入要删除的员工的编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			//职工存在并且需要删除该index位置的职工
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//更新数组中记录的员工个数；
			this->save();		//更新到文件中

			cout << "删除成功。" << endl;


		}
		else
		{
			cout << "职工不存在。" << endl;
		}

	}

	system("pause");
	system("cls");
}

void workmanege::changeEmp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空。" << endl;
	}
	else
	{
		cout << "请输入要修改的员工的编号：" << endl;
		int id = 0;
		string name = "";
		int Did = 0;
		int dselect = 0;
		
		cin >> id;


		int index = this->isExist(id);
		if (index != -1)
		{

			delete this->m_EmpArray[index];

			cout << "请输入新的编号：" << endl;
			cin >> id;

			cout << "请输入新的姓名：" << endl;
			cin >> name;

			cout << "请选择该职工请输入新的岗位：" << endl;
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

			this->m_EmpArray[index] = worker;
			this->save();

			cout << "修改成功。" << endl;
		}
		else
		{
			cout << "查无此人。" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workmanege::findEmp()
{

	bool flag = false;

	if (m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空。" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查找
			int id;
			cout << "请输入职工编号：" << endl;
			cin >> id;
			int ret = isExist(id);
			if (ret!= -1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人。" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查找
			string name;
			cout << "请输入职工姓名：" << endl;
			cin >> name;
			
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功，该职工信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}

			if (flag == false)
			{
				cout << "查找失败，查无此人。" << endl;
			}
		}
		else
		{
			cout << "输入有误。" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workmanege::sortEmp()
{
	worker* temp = NULL;
	for (int i = 0; i < m_EmpNum; i++)
	{
		for (int j = 0; j < m_EmpNum - i - 1; j++)
		{
			if (this->m_EmpArray[j]->m_ID > this->m_EmpArray[j + 1]->m_ID)
			{
				temp = m_EmpArray[j + 1];
				m_EmpArray[j+1] = m_EmpArray[j];
				m_EmpArray[j] = temp;
			}
		}
	}

	cout << "排序成功。" << endl;
	this->save();
	cout << "是否显示排序后结果[Y/N]" << endl;
	string yn;
	cin >> yn;
	if (yn == "y" || yn == "Y")
	{
		showEmp();
	}
	else
	{
		system("pause");
		system("cls");
	}
}

void workmanege::cleanEmp()
{
	cout << "是否确定清空？[Y/N]" << endl;

	string yn;
	cin >> yn;
	if (yn == "y" || yn == "Y")
	{
		ofstream ofs(FILENAME, ios::trunc);		//复写文件，完成清空
		ofs.close();

		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i] != NULL)
				{
					delete m_EmpArray[i];
					m_EmpArray[i] = NULL;
				}
			}

			//删除堆区数组指针
			delete[] m_EmpArray;
			m_EmpArray = NULL;
			m_EmpNum = 0;
			m_FileIsEmpty = true;
		}

		cout << "成功清除文件。" << endl;
	}
	system("pause");
	system("cls");
}

