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
		typedef __list_node<T> node;//private���Σ���Ϊnode��Ҫ����װ��list�ڲ�������Ҫ��¶������
	public:
		//��������Ҫ�����⣬��Ϊ��Ҫ��������ʵ�����
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
