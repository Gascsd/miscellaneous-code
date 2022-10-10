#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"

int main()
{
	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, sizeof(a) / sizeof(a[0]), &i);
	printf("BinaryTreeSize��%d\n", BinaryTreeSize(root));  
	printf("BinaryTreeLeafSize��%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize��%d\n", BinaryTreeLevelKSize(root, 5));

	BTNode* ret = BinaryTreeFind(root, 'A');
	if (ret == NULL)
		printf("BinaryTreeFind��NULL");
	else
		printf("BinaryTreeFind��%c\n", ret->_data);

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

