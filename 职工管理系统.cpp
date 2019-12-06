#include<iostream>
#include "workmanege.h"
#include "worker.h"

void test()
{
	worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}
int main()
{

	test();
	//workmanege wm;
	//while (true)
	//{
	//	wm.showmenu();

	//	cout << "请输入要使用的功能:" << endl;
	//	int select;
	//	cin >> select;
	//	switch (select)
	//	{
	//		case 0: //退出系统
	//			wm.exitsystem();
	//			break;
	//		case 1: //添加职工
	//			break;
	//		case 2: //显示职工
	//			break;
	//		case 3: //删除职工
	//			break;
	//		case 4: //修改职工
	//			break;
	//		case 5: //查找职工
	//			break;
	//		case 6: //排序职工
	//			break;
	//		case 7: //清空文件
	//			break;
	//		default:
	//			system("cls");
	//			break;
	//	}
	//}
	
	system("pause");
	return 0;
}