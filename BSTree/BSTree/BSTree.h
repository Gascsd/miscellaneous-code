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
		bool Insert(const K& key)//插入成功返回true，插入失败返回false
		{
			if (_root == nullptr)//当树为空的情况
			{
				_root = new node(key);
				return true;
			}
			//这里找到叶子节点的时候cur为空，需要让cur的父节点指向新节点，所以需要一个parent保存父节点
			node* parent = nullptr;
			node* cur = _root;
			while (cur)//找到插入位置
			{
				parent = cur;
				if (cur->_key > key)//在左树插入
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)//在右树插入
				{
					cur = cur->_right;
				}
				else//有重复值，不插入
				{
					return false;
				}
			}
			//new一个新节点，并决定插入到左还是右，保证二叉搜索树的结构
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
		//1.对于没有子树的节点，直接delete，然后将父节点的指向nullptr即可
		//2.要删除的节点只有一个子树的时候，进行“托孤”，把该节点的子树交给父节点去管理，然后删除该节点即可
		//3.有两个子树的时候，就要从该节点的子树中找到一个与该节点最接近的值来代替这个位置，然后删除该节点。
		bool Erase(const K& key)
		{
			//当树为空时
			if (_root == nullptr)
				return false;
			node* parent = nullptr;
			node* cur = _root;
			//找到要删除的节点
			while (cur)
			{
				if (cur->_key < key)//找右子树
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)//找左子树
				{
					parent = cur;
					cur = cur->_left;
				}
				else//找到要删除的节点
				{
					if (cur->_left == nullptr)//只有右子树
					{
						if (cur == _root)//如果要删除的节点为根节点/parent==nullptr
							_root = cur->_right;
						else
						{
							if (parent->_left == cur)//当前节点是左树
								parent->_left = cur->_right;
							else //当前节点是右树
								parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr)//只有左子树
					{
						if (cur == _root)//如果要删除的节点为根节点/parent==nullptr
							_root = cur->_right;
						else
						{
							if (parent->_left == cur)//当前节点是左树
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
						delete cur;
					}
					else//有两个子树
					{
						//假设我们这里找右子树的最左节点/最小节点
						parent = cur;
						node* minRight = cur->_right;//初始化成右子树的根节点
						//找到右子树的最小节点
						while (minRight->_left)
						{
							parent = minRight;
							minRight = minRight->_left;
						}
						cur->_key = minRight->_key;//覆盖掉要删除的节点的值
						//删除重复的值
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
					return true;//成功删除，返回true
				}
			}
			//如果没找到/没有，返回false
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
			//后序遍历删除节点，先删除子树，再删除根
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}
		node* Copy(node* root)
		{
			if (root == nullptr)
				return nullptr;
			//前序遍历并new新节点插入到树中
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
		bool _EraseR(node*& root, const K& key)//注意这里root的声明类型是引用
		{
			if (root = nullptr)//没找到符合的节点/树为空
			{
				return false;
			}
			//递归找要删除的节点
			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			//找到了，执行删除
			else
			{
				node* del = root;
				if (root->_left == nullptr)//左树为空
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)//右树为空
				{
					root = root->_left;
				}
				else//左右都不为空
				{
					//找到最小右子树节点，与root交换，删除minRight
					node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);

					// 交换之后，右子树也是符合二叉搜索树的，而且符合没有子树或者只有一个子树的情况
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