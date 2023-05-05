#pragma once
#include <iostream>
using namespace std;

namespace zht
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;
		BSTreeNode(const K& key)
			:_left(nullptr)
			,_right(nullptr)
			,_key(key)
		{}
	};
	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> node;
	public:
		BSTree() :_root(nullptr) {}
		BSTree(const BSTree<K>& t)
		{
			_root = _Copy(t._root);
		}
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}
		~BSTree()
		{
			Destory(_root);
			_root = nullptr;
		}
		bool Insert(const K& key)//����ɹ�����true������ʧ�ܷ���false
		{
			if (_root == nullptr)//����Ϊ�յ����
			{
				_root = new node(key);
				return true;
			}
			//�����ҵ�Ҷ�ӽڵ��ʱ��curΪ�գ���Ҫ��cur�ĸ��ڵ�ָ���½ڵ㣬������Ҫһ��parent���游�ڵ�
			node* parent = nullptr;
			node* cur = _root;
			while (cur)//�ҵ�����λ��
			{
				parent = cur;
				if (cur->_key > key)//����������
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)//����������
				{
					cur = cur->_right;
				}
				else//���ظ�ֵ��������
				{
					return false;
				}
			}
			//newһ���½ڵ㣬���������뵽�����ң���֤�����������Ľṹ
			cur = new node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}
		bool Find(const K& key)
		{
			node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
		//1.����û�������Ľڵ㣬ֱ��delete��Ȼ�󽫸��ڵ��ָ��nullptr����
		//2.Ҫɾ���Ľڵ�ֻ��һ��������ʱ�򣬽��С��й¡����Ѹýڵ�������������ڵ�ȥ����Ȼ��ɾ���ýڵ㼴��
		//3.������������ʱ�򣬾�Ҫ�Ӹýڵ���������ҵ�һ����ýڵ���ӽ���ֵ���������λ�ã�Ȼ��ɾ���ýڵ㡣
		bool Erase(const K& key)
		{
			//����Ϊ��ʱ
			if (_root == nullptr)
				return false;
			node* parent = nullptr;
			node* cur = _root;
			//�ҵ�Ҫɾ���Ľڵ�
			while (cur)
			{
				if (cur->_key < key)//��������
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)//��������
				{
					parent = cur;
					cur = cur->_left;
				}
				else//�ҵ�Ҫɾ���Ľڵ�
				{
					if (cur->_left == nullptr)//ֻ��������
					{
						if (cur == _root)//���Ҫɾ���Ľڵ�Ϊ���ڵ�/parent==nullptr
							_root = cur->_right;
						else
						{
							if (parent->_left == cur)//��ǰ�ڵ�������
								parent->_left = cur->_right;
							else //��ǰ�ڵ�������
								parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr)//ֻ��������
					{
						if (cur == _root)//���Ҫɾ���Ľڵ�Ϊ���ڵ�/parent==nullptr
							_root = cur->_right;
						else
						{
							if (parent->_left == cur)//��ǰ�ڵ�������
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
						delete cur;
					}
					else//����������
					{
						//��������������������������ڵ�/��С�ڵ�
						parent = cur;
						node* minRight = cur->_right;//��ʼ�����������ĸ��ڵ�
						//�ҵ�����������С�ڵ�
						while (minRight->_left)
						{
							parent = minRight;
							minRight = minRight->_left;
						}
						cur->_key = minRight->_key;//���ǵ�Ҫɾ���Ľڵ��ֵ
						//ɾ���ظ���ֵ
						if (minRight == parent->_left)
						{
							parent->_left = minRight->_right;
						}
						else
						{
							parent->_right = minRight->_right;
						}
						delete minRight;
					}
					return true;//�ɹ�ɾ��������true
				}
			}
			//���û�ҵ�/û�У�����false
			return false;
		}
		bool EraseR(const K& key)
		{
			return _EraseR(_root,key);
		}
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:

		void Destory(node* root)
		{
			if (root == nullptr)
				return;
			//�������ɾ���ڵ㣬��ɾ����������ɾ����
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}
		node* Copy(node* root)
		{
			if (root == nullptr)
				return nullptr;
			//ǰ�������new�½ڵ���뵽����
			node* newRoot;
			newRoot = new node(root->_key);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);
			return newRoot;
		}
		bool _FindR(node* root, const K& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_left, key);
			}
			else
				return true;
		}
		bool _InsertR(node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new node(key);
				return true;
			}
			if (root->_key < key)
				_FindR(root->_right, key);
			else if (root->_key > key)
				_FindR(root->_left, key);
			else
				return false;
		}
		bool _EraseR(node*& root, const K& key)//ע������root����������������
		{
			if (root = nullptr)//û�ҵ����ϵĽڵ�/��Ϊ��
			{
				return false;
			}
			//�ݹ���Ҫɾ���Ľڵ�
			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			//�ҵ��ˣ�ִ��ɾ��
			else
			{
				node* del = root;
				if (root->_left == nullptr)//����Ϊ��
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)//����Ϊ��
				{
					root = root->_left;
				}
				else//���Ҷ���Ϊ��
				{
					//�ҵ���С�������ڵ㣬��root������ɾ��minRight
					node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);

					// ����֮��������Ҳ�Ƿ��϶����������ģ����ҷ���û����������ֻ��һ�����������
					return _EraseR(root->_right, key);
				}
				delete del;
				return true;
			}
		}

		void _InOrder(node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	private:
		node* _root = nullptr;

	};


	void Test1()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		BSTree<int> t;
		for (auto e : a)
		{
			t.Insert(e);
		}
		t.InOrder();
		cout << t.FindR(10) << endl;
	}
}