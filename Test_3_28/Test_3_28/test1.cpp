#define _CRT_SECURE_NO_WARNINGS 1

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//1. ѡ���⣺
//ѡ�� : A.ջ B.�� C.���ݶ�(��̬��) D.�����(������)
//globalVar�����__C__  staticGlobalVar�����__C__
//staticVar�����__C__  localVar�����__A__
//num1 �����__A__
//char2�����__A__ *char2�����__A__
//pChar3�����__A__ *pChar3�����__D__
//ptr1�����__A__ *ptr1�����__B__
//2. ����⣺
//sizeof(num1) = __40__;
//sizeof(char2) = __5__;   strlen(char2) = __4__;
//sizeof(pChar3) = __4__;   strlen(pChar3) = __4__;
//sizeof(ptr1) = __4__;