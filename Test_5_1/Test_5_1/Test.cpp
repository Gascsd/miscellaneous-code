#include <iostream>
using namespace std;

//class Person
//{
//public:
//	Person(const char* name = "zht")
//		:_name(name)
//	{
//		cout << "Person(const char* name)" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//};
//class student : public Person
//{
//public:
//	student(const char* name = "zht", int num = 11111)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "student()" << endl;
//	}
//	student(const student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const student& s)" << endl;
//	}
//	student& operator = (const student& s)
//	{
//		cout << "student& operator= (const student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~student()
//	{
//		cout << "~student()" << endl;
//	}
//protected:
//	int _num; //学号
//};
////class student : public Person
////{
////protected:
////	int _stuid = 1111111;//学号
////	string _major = "CST";//专业
////	int _num = 666;
////};
//class teacher : public Person
//{
//protected:
//	int _jobid = 2222222;//工号
//};
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "B::fun(int i)" << i << endl;
//	}
//};
//void Test5()
//{
//	cout << "测试构造和析构" << endl;
//	student s;
//	cout << "测试拷贝构造" << endl;
//	student s1(s);
//}
//void Test4()
//{
//	B b;
//	b.fun();
//}
//void Test1()
//{
//	student stu;
//	teacher t;
//	stu.print();
//	t.print();
//}
//void Test2()
//{
//	student s;
//	//1.子类对象赋值给父类：对象/指针/引用
//	Person p = s;
//	Person* pp = &s;
//	Person& rp = s;
//
//	//2.基类对象不能赋值给派生类对象
//	s = p;
//
//	//3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &s;
//	student* ps1 = (student*)pp; // 这种情况转换时可以的。
//	ps1->_stuid = 10;
//	pp = &p;
//	student* ps2 = (student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_stuid = 10;
//}
//void Test3()
//{
//	student s;
//	cout << s._num << endl;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void Test6()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
string _seminarCourse; // 研究科目
};
void Test7()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "人数:" << Person::_count << endl;
	Student::_count = 0;
	cout << "人数:" << Person::_count << endl;
}

//class Person
//{
//public:
//	string _name; // 姓名
//};
////class Student : public Person
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
////class Teacher : public Person
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//}



class A
{
public:
	int _a;
};
//class B : public A
class B : virtual public A
{
public:
	int _b;
};
//class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
void Test8()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
}
class M
{

};
class N : public M//public继承
{

};
class X//组合
{
public:
	M mm;
};
int main()
{
	Test8();
	return 0;
}