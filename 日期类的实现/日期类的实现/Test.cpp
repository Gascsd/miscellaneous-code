#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
using namespace std;

int main()
{
	//���Թ��캯��
	Date d1;
	Date d2(2022, 9, 22);
	//���Թ��쿽��
	Date d3(d1);
	//���Ը�ֵ���������
	d1 = d2;
	//����+����
	d3 = d2 + 50;
	//����+=����
	d2 += 50;
	//����-����
	d3 = d2 - 50;
	//����-=����
	d2 -= 50;
	//����ǰ��++
	d3 += 8;
	++d3;
	//���Ժ���++
	//���Ժ���--
	//����ǰ��--

	//����>���������
	cout << (d1 > d2) << endl;
	cout << (d3 > d1) << endl;
	//����==���������
	cout << (d1 == d2) << endl;
	cout << (d3 == d2) << endl;
	//����>=���������
	cout << (d1 >= d2) << endl;
	cout << (d2 > d3) << endl;
	//����<���������
	cout << (d1 < d2) << endl;
	cout << (d1 < d3) << endl;
	//����<=���������
	cout << (d3 <= d2) << endl;
	cout << (d1 <= d2) << endl;
	//����!=���������
	cout << (d1 != d2) << endl;
	cout << (d3 != d2) << endl;
	// ��������-���� ��������


	//������������
	return 0;
}