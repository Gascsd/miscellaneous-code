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
//	int _num; //ѧ��
//};
////class student : public Person
////{
////protected:
////	int _stuid = 1111111;//ѧ��
////	string _major = "CST";//רҵ
////	int _num = 666;
////};
//class teacher : public Person
//{
//protected:
//	int _jobid = 2222222;//����
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
//	cout << "���Թ��������" << endl;
//	student s;
//	cout << "���Կ�������" << endl;
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
//	//1.�������ֵ�����ࣺ����/ָ��/����
//	Person p = s;
//	Person* pp = &s;
//	Person& rp = s;
//
//	//2.��������ܸ�ֵ�����������
//	s = p;
//
//	//3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &s;
//	student* ps1 = (student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_stuid = 10;
//	pp = &p;
//	student* ps2 = (student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
string _seminarCourse; // �о���Ŀ
};
void Test7()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "����:" << Person::_count << endl;
	Student::_count = 0;
	cout << "����:" << Person::_count << endl;
}

//class Person
//{
//public:
//	string _name; // ����
//};
////class Student : public Person
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
////class Teacher : public Person
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
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
class N : public M//public�̳�
{

};
class X//���
{
public:
	M mm;
};
int main()
{
	Test8();
	return 0;
}