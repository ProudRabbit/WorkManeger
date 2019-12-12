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