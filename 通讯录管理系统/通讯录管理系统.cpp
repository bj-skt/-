#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//�����ϵ�˽ṹ��
struct person
{
	string m_name;
	int m_sex;//1.��  2.Ů
	int m_age;
	string m_phone;
	string m_addr;
};
//ͨѶ¼�ṹ��
struct addressbooks {
	person personarray[MAX];
	int m_size;
};
//1.�����ϵ��
void addperson(addressbooks *abs) {
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼�������޷����!" << endl;
		return;
	}
	else{
	//��Ӿ�����ϵ��
	//����
		string name;
		cout << "������������" <<endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
	//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1--Ů" << endl;
		cout << "2--��" << endl;
		int sex = 0;
		cin >> sex;
		while (true) {
			
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
			cin >> sex;
		}		
	//����
		cout << "���������䣺"<<endl;
		int age = 0;
		cin >> age;
		while (true)
		{
			if (age > 0 && age < 200) {
				abs->personarray[abs->m_size].m_age = age;
				break;
			}
			cout << "������������������" << endl;
			cin >> age;
		}
		
	//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
	//סַ
		cout << "������סַ��" << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->m_size].m_addr = addr;
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
		}
}
//2.��ʾ��ϵ��
void showperson(addressbooks *abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ��ʾ��¼Ϊ��
	if (abs->m_size == 0) {
		cout << "��ǰ��¼Ϊ��"<<endl;
	}
	else
		for (int i = 0; i < abs->m_size; i++) {
			//����
			cout << "������" << abs->personarray[i].m_name <<"\t";
				//�Ա�
			cout << "�Ա�" << (abs->personarray[i].m_sex == 1 ? "��":"Ů") << "\t";
				//����
			cout << "���䣺" << abs->personarray[i].m_age << "\t";
				//�绰
			cout << "�绰��" << abs->personarray[i].m_phone << "\t";
				//סַ
			cout << "סַ��" << abs->personarray[i].m_addr<< endl;
		}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
int isexit(addressbooks *abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {

		if (abs->personarray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}
//3.ɾ��ָ����ϵ��
void delateperson(addressbooks *abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret == -1)
		cout << "���޴���" << endl;
	else {
		for (int i = ret; ret < abs->m_size; i++) {
			abs->personarray[i] = abs->personarray[i + 1];		
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks *abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	//�ж���ϵ���Ƿ���ͨѶ¼��	
	if (ret == -1)
		cout << "���޴���" << endl;
	else
	{
		cout << "������" << abs->personarray[ret].m_name << "\t";
		//�Ա�
		cout << "�Ա�" << (abs->personarray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		//����
		cout << "���䣺" << abs->personarray[ret].m_age << "\t";
		//�绰
		cout << "�绰��" << abs->personarray[ret].m_phone << "\t";
		//סַ
		cout << "סַ��" << abs->personarray[ret].m_addr << endl;
		}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks *abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��:" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1) {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1--Ů" << endl;
		cout << "2--��" << endl;
		int sex = 0;
		cin >> sex;
		while (true) {

			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
			cin >> sex;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		while (true)
		{
			if (age > 0 && age < 300) {
				abs->personarray[ret].m_age = age;
				break;
			}
			cout << "������������������" << endl;
			cin >> age;
		}
		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;		
		cout << "�޸ĳɹ�" << endl;		
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks *abs) {
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
void showmenu() {
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
}
int main()
{
	//����ͨѶ¼�ṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;
	int select = 0;
	while (true) {
		showmenu();
		cin >> select;
		switch (select) {
		case 1://1.�����ϵ��
			addperson(&abs);
			break;
		case 2://2.��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://3.ɾ����ϵ��
			{cout << "������ɾ����ϵ��������" << endl;
			string name;
			cin >> name;
			delateperson(&abs);		
		break; }
		case 4://4.������ϵ��
			findperson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://6.�����ϵ��
			cleanperson(&abs);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default: {
			cout << "����������" << endl;
			system("pause");
			system("cls"); }
		}
	}	
	system("pause");
	return 0;
}