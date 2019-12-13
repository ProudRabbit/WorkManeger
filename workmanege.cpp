#include"workmanege.h"

workmanege::workmanege()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���ļ�

	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڡ�" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	//�ļ�Ϊ��
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�ա�" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�����
	int num = getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new worker * [this->m_EmpNum];	//���ٿռ�
	this->init_Emp();		//���ļ���ȡ�����ٵĶ����ռ�

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
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workmanege::exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void workmanege:: addEmp()
{
	cout << "������Ҫ��ӵ�ְ��������"<<endl;
	int addnum = 0;	//�����û�Ҫ��ӵ�ְ��������
	cin >> addnum;

	if (addnum > 0)
	{
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addnum;	//�¿ռ��С����ԭ����������������ӵ�������
		//�����¿ռ�

		worker** newspace = new worker* [newSize];
		
		//��ԭ�������ݿ������¿ռ�
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newspace[i] = m_EmpArray[i];
			}

		}
		//�������������
		for (int i = 0; i < addnum; i++)
		{
			int id;		//ְ��ID
			string name;	//����
			int dselect;	//���ű��

			cout << "�������" << i + 1 << "��ְ���ı�ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ����������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			//��������ְ����Ϣ���浽������
			newspace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] m_EmpArray;

		//��¼�¿ռ��ַ
		m_EmpArray = newspace;

		//����Ա����Ϣ
		m_EmpNum = newSize;

		//�����ļ���Ϊ�ձ�־
		m_FileIsEmpty = false;

		cout << "�ɹ����"<<addnum<< "��Ա����"<< endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
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
		cout << "�ļ������ڻ���Ϊ�ա�" << endl;
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
		cout << "�ļ��������Ҽ�¼Ϊ�ա�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա���ı�ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			//ְ�����ڲ�����Ҫɾ����indexλ�õ�ְ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//���������м�¼��Ա��������
			this->save();		//���µ��ļ���

			cout << "ɾ���ɹ���" << endl;


		}
		else
		{
			cout << "ְ�������ڡ�" << endl;
		}

	}

	system("pause");
	system("cls");
}

void workmanege::changeEmp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�ա�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա���ı�ţ�" << endl;
		int id = 0;
		string name = "";
		int Did = 0;
		int dselect = 0;
		
		cin >> id;


		int index = this->isExist(id);
		if (index != -1)
		{

			delete this->m_EmpArray[index];

			cout << "�������µı�ţ�" << endl;
			cin >> id;

			cout << "�������µ�������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���������µĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "���޴��ˡ�" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ�ա�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų���
			int id;
			cout << "������ְ����ţ�" << endl;
			cin >> id;
			int ret = isExist(id);
			if (ret!= -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴��ˡ�" << endl;
			}
		}
		else if (select == 2)
		{
			//������������
			string name;
			cout << "������ְ��������" << endl;
			cin >> name;
			
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}

			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˡ�" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
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

	cout << "����ɹ���" << endl;
	this->save();
	cout << "�Ƿ���ʾ�������[Y/N]" << endl;
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
	cout << "�Ƿ�ȷ����գ�[Y/N]" << endl;

	string yn;
	cin >> yn;
	if (yn == "y" || yn == "Y")
	{
		ofstream ofs(FILENAME, ios::trunc);		//��д�ļ���������
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

			//ɾ����������ָ��
			delete[] m_EmpArray;
			m_EmpArray = NULL;
			m_EmpNum = 0;
			m_FileIsEmpty = true;
		}

		cout << "�ɹ�����ļ���" << endl;
	}
	system("pause");
	system("cls");
}

