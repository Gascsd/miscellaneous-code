#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
		if (tmp == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		tmp->_data = a[*pi];
		(*pi)++;
		tmp->_left = BinaryTreeCreate(a, n, pi);
		tmp->_right = BinaryTreeCreate(a, n, pi);
		return tmp;
	}
	else
	{
		(*pi)++;
		return NULL;
	}
}
// ����������
void BinaryTreeDestory(BTNode** proot)
{
	assert(proot);
	if (*proot == NULL)
		return;
	BinaryTreeDestory(&((*proot)->_left));
	BinaryTreeDestory(&((*proot)->_right));
	free(*proot);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//assert(k < 1);
	if (k <= 1)
		return root == NULL ? 0 : 1;
	else if (root == NULL)
		return 0;
	else
		return BinaryTreeLevelKSize(root->_left, k - 1) 
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret != NULL)
		return ret;

	ret = BinaryTreeFind(root->_right, x);
	if (ret != NULL)
		return ret;
	return NULL;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		printf("NULL ");
	else
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		printf("NULL ");
	else
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		printf("NULL ");
	else
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}

}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return;
	else
	{
		QueuePush(&q, root);
		while (!QueueEmpty(&q))
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			printf("%c ", front->_data);
			//��һ�������
			if(front->_left)
				QueuePush(&q, front->_left);
			if (front->_right)
				QueuePush(&q, front->_right);
		}
	}

	QueueDestory(&q);
}
//�ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return;
	else
	{
		QueuePush(&q, root);
		while (!QueueEmpty(&q))
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			if (front == NULL)
				break;
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		//�������Ժ����ȫ�ǿ�˵������ȫ��������������
		while (!QueueEmpty(&q))
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			if (front != NULL)
				return false;
		}
	}

	QueueDestory(&q);
	return true;
}