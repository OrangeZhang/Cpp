#include "iostream"
using namespace std;

struct TestStruct
{
	int iNumber;
	char charArray[10];
	char ch;
	double dNumber;
};

//Ƕ�׵Ľṹ�����ͳ�Ա
struct Date
{
	int Day;
	int Month;
	int Year;
};

struct Person  //����ṹ��
{
	char Name[20];
	int Age;
	struct Date Birthday;//Ƕ��Date�ṹ�����ͳ�Ա
};

//�ṹ���е�ָ���Ա
struct Student
{
	char *name;
	int score;
	struct Student *next;
};

int main(int argc, char *argv[])
{
	//�ṹ��Ĵ�С
	//A;�ṹ��������׵�ַ�ܹ��������������ͳ�Ա�Ĵ�С������
	//B:�ṹ��ÿ����Ա��Խṹ���׵�ַ��ƫ�������ǳ�Ա�����С����������������Ҫ���������ڳ�Ա֮���������ֽ�
	//C:�ṹ����ܴ�СΪ�ṹ�����������ͳ�Ա��С��������
	cout << "Size of TestStruct:  " << sizeof(TestStruct) << endl;  //����ó�23�ֽ�   ʵ�����Ϊ24�ֽ�  �ο�C  �������Ϊdouble(8�ֽ�) ����Ϊdouble�������������Զ�����Ϊ24
	cout << "Size of Date:  " << sizeof(Date) << endl;  //12�ֽ�
	cout << "Size of Person:  " << sizeof(Person) << endl; //36�ֽ�

	//�ṹ�����
	TestStruct t = { 5, "bcdefg", 'a', 1.1 };
	cout << "TestStruct ch:  " << t.ch << "charArray:  " << t.charArray << "dNumber:  " << t.dNumber << "iNumber:  " << t.iNumber << endl<<endl;

	//�ṹ������
	TestStruct tt[3] = {{ 8, "bcdefg", 'm', 1.2 },
						{ 6, "hijklm", 'b', 2.2 },
						{ 7, "nopqrs", 'c', 3.3 }};

	for (int i = 0; i < 3; i++)
	{
		cout << "TestStruct[" << i << "]ch:  " << tt[i].ch << "  charArray:  " << tt[i].charArray << "  dNumber:  " << tt[i].dNumber << "  iNumber:  " << tt[i].iNumber << endl;
	}
	cout << endl;

	//ָ�������ṹ�����
	//������ṹ��ָ���������һ����Ч�Ľṹ�������ֵ���������������ṹ��ָ�����
	//TsetStruct *p = &t;ŷ�󽫳��ֲ���Ԥ֪�����⡣(*p).ch�ȼ��� p->ch
	TestStruct *p = &t;
	cout << "TestStruct p->ch:" << p->ch << "  p->charArray: " << p->charArray << "  p->dNumber: " << p->dNumber << "  p->iNumber: " << p->iNumber << endl<<endl;

	//ָ��ṹ�������ָ��
	//pp�ĳ�ʼֵΪtt����ָ���һ��Ԫ�أ���pp��1��pp��������һ��Ԫ�ص���ʼ��ַ����tt[1]����ʼ��ַ)
	TestStruct *pp;
	for (pp = tt; pp < tt + 3; ++pp){
		cout << "TestStruct p->ch:" << pp->ch << "  p->charArray: " << pp->charArray << "  p->dNumber: " << pp->dNumber << "  p->iNumber: " << pp->iNumber << endl;
	}
	cout << endl;

	//Ƕ�׽ṹ�����ͳ�Ա
	//����Ƕ�׽ṹ��Date�ĳ�Աper->Birthday.Year�ȼ���(*per).Birthday.Year
	Person *per;
	per = new Person;//per = (Person *)malloc(sizeof(Person));
	cout << "Inptu name,age,year,month,day" << endl;
	cin >> per->Name >> per->Age >> per->Birthday.Year >> per->Birthday.Month >> per->Birthday.Day;
	cout << "Name:" << per->Name << " Age:" << per->Age << " Birthday:" << (*per).Birthday.Year << "/" << per->Birthday.Month << "/" << per->Birthday.Day << endl << endl;
	delete per;//free(per);

	//�ṹ���е�ָ���Ա
	Student stu, *Pstu;
	//�ṹ���Աָ����Ҫ��ʼ��
	stu.name = new char[4];//stu.name = (char*)malloc(sizeof(char));  name��ָ��������Ҫnew
	//strcpy(stu.name, "ddd");
	stu.name = "ddd";
	cout << stu.name << endl;
	stu.name = "add";
	cout << stu.name << endl;
	stu.score = 99;
	//�ṹ��ָ����Ҫ��ʼ��
	Pstu = new Student;//Pstu->name = (char*)malloc(sizeof(char));
	stu.next = Pstu;
	Pstu->name = "ffff";
	//strcpy(Pstu->name, "dddd");
	Pstu->score = 88;
	Pstu->next = NULL;
	cout << "stu.name: " << stu.name << "  stu.score: " << stu.score << endl;
	cout << "stu.next->name:" << stu.next->name <<"  stu.next->score: " << stu.next->score << endl;
	cout << "Pstu->name: " << Pstu->name << "  Pstu->score: " << Pstu->score << endl;
	delete Pstu;

	return 0;
}