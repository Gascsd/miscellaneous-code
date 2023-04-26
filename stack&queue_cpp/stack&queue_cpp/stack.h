#pragma once
#include <deque>

namespace zht
{
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		//构造函数：我们不显示写，编译器生成。直接调用_con的默认构造
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
			return _con.back();//适配这类操作的容器都是支持back或者front接口的，直接调用即可
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
