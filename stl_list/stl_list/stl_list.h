#pragma once

namespace zht
{
	template<class T>
	struct __list_node
	{
		__list_node* _prev;
		__list_node* _next;
		T _data;
		__list_node(const T& data = T())
			:_data(data)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};
	//typedef __list_iterator<T, T&, T*> iterator;
	//typedef __list_iterator<T, const T&, const T*> const_iterator;
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		node* _pnode;

		__list_iterator(node* p)
			:_pnode(p)
		{}
		Ptr operator->()
		{
			return &_pnode->_data;
		}
		Ref operator*()
		{
			return _pnode->_data;
		}
		Self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}
		bool operator!=(const Self it)
		{
			return _pnode != it._pnode;
		}
		bool operator==(const Self it)
		{
			return _pnode == it._pnode;
		}

	};
	template<class T>
	class list
	{
		typedef __list_node<T> node;//private修饰，因为node需要被封装在list内部，不需要暴露在类外
	public:
		//迭代器需要在类外，因为需要在外面访问迭代器
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		list()
		{
			_head = new node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(const T& x = T())
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;
			//_head    tail   newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		node* _head;
	};
}
