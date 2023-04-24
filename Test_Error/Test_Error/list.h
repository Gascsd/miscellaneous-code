#pragma once
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
	template<class T>
	class list
	{
		typedef __list_node<T> node;//private修饰，因为node需要被封装在list内部，不需要暴露在类外
	public:
		//迭代器需要在类外，因为需要在外面访问迭代器
		list()
		{
			_head = new node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(const T& x = T())
		{
			node* newnode = new node(x);
			_head->_prev = newnode;
			newnode->_next = _head;
			newnode->_prev =
		}

	private:
		node* _head;
	};
}
