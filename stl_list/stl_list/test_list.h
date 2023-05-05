#pragma once
#include <utility>
#include <iostream>
namespace my
{
	template<class T>
	struct __list_node//����һ��list�Ľڵ���ģ��
	{
		__list_node* _prev;
		__list_node* _next;
		T _data;
		__list_node(const T& data = T())//__list_node��Ĭ�Ϲ��캯��
			:_data(data)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;//�������ڵ���
		typedef __list_iterator<T, Ref, Ptr> Self;
		node* _pnode;//�������ĳ�Ա�������ǽ��ָ��

		__list_iterator(node* p)//�������Ĺ��캯��
			:_pnode(p)
		{}
		Ptr operator->()
		{
			return &operator*();
		}
		Ref operator*()//����*�������Ƿ���ָ��Ľڵ��Ԫ��ֵ
		{
			return _pnode->_data;
		}
		Self& operator++()//����++�������ǽ�����������1
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
		Self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
		bool operator!=(const Self& it)
		{
			return _pnode != it._pnode;
		}
		bool operator==(const Self& it)
		{
			return _pnode == it._pnode;
		}
	};

	template<class T>
	class list//����һ��list�࣬���еĳ�Ա����ֻ��һ��ͷ�ڵ㡣
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;//��ͨ������
		typedef __list_iterator<T, const T&, const T*> const_iterator;//const������
		//typedef __list_const_iterator<T> const_iterator;//const������
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}
		void empty_initialize()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list()
		{
			empty_initialize();
		}
		list(size_t n, const T& val = T())
		{
			empty_initialize();
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_initialize();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//list(const list<T>& lt)//����д��
		//{
		//    empty_initialize();
		//    for (const auto& e : lt)
		//    {
		//        push_back(e);
		//    }
		//}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}
		list(const list<T>& lt)//�ִ�д��
		{
			empty_initialize();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		list<T>& operator=(list<T>& lt)//����д��
		{
			if (this != *lt)//��ֹ�Լ����Լ���ֵ
			{
				clear();
				for (auto& e : lt)
				{
					push_back(e);
				}
			}
		}
		//list<T>& operator=(list<T> lt)//�ִ�д��
		//{
		//	swap(lt);
		//	return *this;
		//}
		bool empty()
		{
			return _head->_next == _head;
		}
		void clear()
		{
			while (!empty())
			{
				erase(--end());
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void push_back(const T& val = T())
		{
			insert(end(), val);
		}
		void push_front(const T& val = T())
		{
			insert(begin(), val);
		}
		iterator insert(iterator pos, const T& val = T())
		{
			node* newnode = new node(val);
			//   prev   newnode   cur
			node* prev = pos._pnode->_prev;
			node* cur = pos._pnode;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;
			return iterator(newnode);
		}

		size_t size()
		{
			return _size;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos._pnode->_prev;
			node* next = pos._pnode->_next;
			//prev    cur    next
			prev->_next = next;
			next->_prev = prev;
			delete pos._pnode;
			--_size;
			return iterator(next);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void resize(size_t n, const T& val = T())
		{
			while (n < size())
			{
				pop_back();
			}
			while (n > size())
			{
				push_back(val);
			}
		}
	private:
		node* _head;
		size_t _size;
	};
	void Test()
	{
		my::list<int> lt;
		my::list<int>::const_iterator begin = lt.begin();
	}
}
