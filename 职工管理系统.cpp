#include<iostream>
#include "workmanege.h"
#include "worker.h"

//void test()
//{
//	worker* worker = NULL;
//	worker = new Employee(1, "����", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "����", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "����", 3);
//	worker->showInfo();
//	delete worker;
//}
int main()
{

	//test();
	workmanege wm;
	while (true)
	{
		wm.showmenu();

		cout << "������Ҫʹ�õĹ���:" << endl;
		int select;
		cin >> select;
		switch (select)
		{
			case 0: //�˳�ϵͳ
				wm.exitsystem();
				break;
			case 1: //���ְ��
				wm.addEmp();
				break;
			case 2: //��ʾְ��
				wm.showEmp();
				break;
			case 3: //ɾ��ְ��
				wm.delEmp();
				break;
			case 4: //�޸�ְ��
				wm.changeEmp();
				break;
			case 5: //����ְ��
				wm.findEmp();
				break;
			case 6: //����ְ��
				wm.sortEmp();
				break;
			case 7: //����ļ�
				wm.cleanEmp();
				break;
			default:
				system("cls");
				break;
		}
	}
	
	system("pause");
	return 0;
}