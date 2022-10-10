#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"

int main()
{
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, sizeof(a) / sizeof(a[0]), &i);
	printf("BinaryTreeSize£º%d\n", BinaryTreeSize(root));  
	printf("BinaryTreeLeafSize£º%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize£º%d\n", BinaryTreeLevelKSize(root, 5));

	BTNode* ret = BinaryTreeFind(root, 'A');
	if (ret == NULL)
		printf("BinaryTreeFind£ºNULL");
	else
		printf("BinaryTreeFind£º%c\n", ret->_data);

	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("%d\n", BinaryTreeComplete(root));

	BinaryTreeDestory(&root);
	return 0;
}

