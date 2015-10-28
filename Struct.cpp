#include "iostream"
using namespace std;

struct TestStruct
{
	int iNumber;
	char charArray[10];
	char ch;
	double dNumber;
};

//嵌套的结构体类型成员
struct Date
{
	int Day;
	int Month;
	int Year;
};

struct Person  //定义结构体
{
	char Name[20];
	int Age;
	struct Date Birthday;//嵌套Date结构体类型成员
};

//结构体中的指针成员
struct Student
{
	char *name;
	int score;
	struct Student *next;
};

int main(int argc, char *argv[])
{
	//结构体的大小
	//A;结构体变量的首地址能够被其最宽基本类型成员的大小所整除
	//B:结构体每个成员相对结构体首地址的偏移量都是成员自身大小的整数倍，如有需要编译器会在成员之间加上填充字节
	//C:结构体的总大小为结构体最宽基本类型成员大小的整数倍
	cout << "Size of TestStruct:  " << sizeof(TestStruct) << endl;  //计算得出23字节   实际输出为24字节  参考C  最大类型为double(8字节) 必须为double的整数倍所以自动补足为24
	cout << "Size of Date:  " << sizeof(Date) << endl;  //12字节
	cout << "Size of Person:  " << sizeof(Person) << endl; //36字节

	//结构体变量
	TestStruct t = { 5, "bcdefg", 'a', 1.1 };
	cout << "TestStruct ch:  " << t.ch << "charArray:  " << t.charArray << "dNumber:  " << t.dNumber << "iNumber:  " << t.iNumber << endl<<endl;

	//结构体数组
	TestStruct tt[3] = {{ 8, "bcdefg", 'm', 1.2 },
						{ 6, "hijklm", 'b', 2.2 },
						{ 7, "nopqrs", 'c', 3.3 }};

	for (int i = 0; i < 3; i++)
	{
		cout << "TestStruct[" << i << "]ch:  " << tt[i].ch << "  charArray:  " << tt[i].charArray << "  dNumber:  " << tt[i].dNumber << "  iNumber:  " << tt[i].iNumber << endl;
	}
	cout << endl;

	//指针变量与结构体变量
	//必须给结构体指针变量赋予一个有效的结构体变量低值，才能正常操作结构体指针变量
	//TsetStruct *p = &t;欧泽将出现不可预知的问题。(*p).ch等价于 p->ch
	TestStruct *p = &t;
	cout << "TestStruct p->ch:" << p->ch << "  p->charArray: " << p->charArray << "  p->dNumber: " << p->dNumber << "  p->iNumber: " << p->iNumber << endl<<endl;

	//指向结构体数组的指针
	//pp的初始值为tt，即指向第一个元素，则pp加1后pp就智商下一个元素的起始地址（即tt[1]得起始地址)
	TestStruct *pp;
	for (pp = tt; pp < tt + 3; ++pp){
		cout << "TestStruct p->ch:" << pp->ch << "  p->charArray: " << pp->charArray << "  p->dNumber: " << pp->dNumber << "  p->iNumber: " << pp->iNumber << endl;
	}
	cout << endl;

	//嵌套结构体类型成员
	//访问嵌套结构体Date的成员per->Birthday.Year等价于(*per).Birthday.Year
	Person *per;
	per = new Person;//per = (Person *)malloc(sizeof(Person));
	cout << "Inptu name,age,year,month,day" << endl;
	cin >> per->Name >> per->Age >> per->Birthday.Year >> per->Birthday.Month >> per->Birthday.Day;
	cout << "Name:" << per->Name << " Age:" << per->Age << " Birthday:" << (*per).Birthday.Year << "/" << per->Birthday.Month << "/" << per->Birthday.Day << endl << endl;
	delete per;//free(per);

	//结构体中的指针成员
	Student stu, *Pstu;
	//结构体成员指针需要初始化
	stu.name = new char[4];//stu.name = (char*)malloc(sizeof(char));  name是指针所以需要new
	//strcpy(stu.name, "ddd");
	stu.name = "ddd";
	cout << stu.name << endl;
	stu.name = "add";
	cout << stu.name << endl;
	stu.score = 99;
	//结构体指针需要初始化
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