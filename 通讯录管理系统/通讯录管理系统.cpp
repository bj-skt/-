#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//设计联系人结构体
struct person
{
	string m_name;
	int m_sex;//1.男  2.女
	int m_age;
	string m_phone;
	string m_addr;
};
//通讯录结构体
struct addressbooks {
	person personarray[MAX];
	int m_size;
};
//1.添加联系人
void addperson(addressbooks *abs) {
	if (abs->m_size == MAX) {
		cout << "通讯录已满，无法添加!" << endl;
		return;
	}
	else{
	//添加具体联系人
	//姓名
		string name;
		cout << "请输入姓名：" <<endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
	//性别
		cout << "请输入性别：" << endl;
		cout << "1--女" << endl;
		cout << "2--男" << endl;
		int sex = 0;
		cin >> sex;
		while (true) {
			
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
			cin >> sex;
		}		
	//年龄
		cout << "请输入年龄："<<endl;
		int age = 0;
		cin >> age;
		while (true)
		{
			if (age > 0 && age < 200) {
				abs->personarray[abs->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
			cin >> age;
		}
		
	//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
	//住址
		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->m_size].m_addr = addr;
		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
		}
}
//2.显示联系人
void showperson(addressbooks *abs) {
	//判断通讯录中人数是否为提示记录为空
	if (abs->m_size == 0) {
		cout << "当前记录为空"<<endl;
	}
	else
		for (int i = 0; i < abs->m_size; i++) {
			//姓名
			cout << "姓名：" << abs->personarray[i].m_name <<"\t";
				//性别
			cout << "性别：" << (abs->personarray[i].m_sex == 1 ? "男":"女") << "\t";
				//年龄
			cout << "年龄：" << abs->personarray[i].m_age << "\t";
				//电话
			cout << "电话：" << abs->personarray[i].m_phone << "\t";
				//住址
			cout << "住址：" << abs->personarray[i].m_addr<< endl;
		}
	system("pause");
	system("cls");
}
//检测联系人是否存在
int isexit(addressbooks *abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {

		if (abs->personarray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}
//3.删除指定联系人
void delateperson(addressbooks *abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret == -1)
		cout << "查无此人" << endl;
	else {
		for (int i = ret; ret < abs->m_size; i++) {
			abs->personarray[i] = abs->personarray[i + 1];		
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks *abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	//判断联系人是否在通讯录中	
	if (ret == -1)
		cout << "查无此人" << endl;
	else
	{
		cout << "姓名：" << abs->personarray[ret].m_name << "\t";
		//性别
		cout << "性别：" << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
		//年龄
		cout << "年龄：" << abs->personarray[ret].m_age << "\t";
		//电话
		cout << "电话：" << abs->personarray[ret].m_phone << "\t";
		//住址
		cout << "住址：" << abs->personarray[ret].m_addr << endl;
		}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks *abs)
{
	cout << "请输入您要修改的联系人:" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1--女" << endl;
		cout << "2--男" << endl;
		int sex = 0;
		cin >> sex;
		while (true) {

			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
			cin >> sex;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		while (true)
		{
			if (age > 0 && age < 300) {
				abs->personarray[ret].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
			cin >> age;
		}
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;		
		cout << "修改成功" << endl;		
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks *abs) {
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
void showmenu() {
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
}
int main()
{
	//创建通讯录结构体变量
	addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_size = 0;
	int select = 0;
	while (true) {
		showmenu();
		cin >> select;
		switch (select) {
		case 1://1.添加联系人
			addperson(&abs);
			break;
		case 2://2.显示联系人
			showperson(&abs);
			break;
		case 3://3.删除联系人
			{cout << "请输入删除联系人姓名：" << endl;
			string name;
			cin >> name;
			delateperson(&abs);		
		break; }
		case 4://4.查找联系人
			findperson(&abs);
			break;
		case 5://5.修改联系人
			modifyperson(&abs);
			break;
		case 6://6.清空联系人
			cleanperson(&abs);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default: {
			cout << "请重新输入" << endl;
			system("pause");
			system("cls"); }
		}
	}	
	system("pause");
	return 0;
}