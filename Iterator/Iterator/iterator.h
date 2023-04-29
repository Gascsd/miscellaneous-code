#pragma once
namespace zht
{
	template<class Iterator, class Ref, class Ptr>//这里对参数的设计参考之前list迭代器的这几
	class reverse_iterator
	{
		typedef reverse_iterator<Iterator, Ref, Ptr> Self;//这里类型实例化出来太长了，做一个重命名
	public:
		reverse_iterator(Iterator it)//构造函数
			:_it(it)
		{}
		Self& operator++()//前置++
		{
			--_it;
			return *this;
		}
		Self operator++(int)//后置++
		{
			Self tmp = _it;
			--_it;
			return tmp;
		}
		Self& operator--()//前置--
		{
			++_it;
			return *this;
		}
		Self operator--(int)//后置--
		{
			Self tmp = _it;
			++_it;
			return tmp;
		}
		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		bool operator!= (const Self& s) const
		{
			return _it != s._it;
		}
		bool operator==(const Self& s) const
		{
			return _it == s._it;
		}
	private:
		Iterator _it;
	};
}