#pragma once
#include <deque>

namespace zht
{
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		//���캯�������ǲ���ʾд�����������ɡ�ֱ�ӵ���_con��Ĭ�Ϲ���
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top() 
		{
			return _con.back();//���������������������֧��back����front�ӿڵģ�ֱ�ӵ��ü���
		}
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_back();
		}
	private:
		Container _con;
	};
}
