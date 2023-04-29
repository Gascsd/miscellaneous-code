#pragma once
namespace zht
{
	template<class Iterator, class Ref, class Ptr>//����Բ�������Ʋο�֮ǰlist���������⼸
	class reverse_iterator
	{
		typedef reverse_iterator<Iterator, Ref, Ptr> Self;//��������ʵ��������̫���ˣ���һ��������
	public:
		reverse_iterator(Iterator it)//���캯��
			:_it(it)
		{}
		Self& operator++()//ǰ��++
		{
			--_it;
			return *this;
		}
		Self operator++(int)//����++
		{
			Self tmp = _it;
			--_it;
			return tmp;
		}
		Self& operator--()//ǰ��--
		{
			++_it;
			return *this;
		}
		Self operator--(int)//����--
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