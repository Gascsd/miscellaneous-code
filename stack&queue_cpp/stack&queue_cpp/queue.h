#pragma once

#include <deque>

namespace zht
{
	template<class T, class Container = std::deque<T>>
	class queue
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
		const T& front()
		{
			return _con.front();//���������������������֧��back����front�ӿڵģ�ֱ�ӵ��ü���
		}
		const T& back()
		{
			return _con.back();
		}
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
	private:
		Container _con;
	};
}
