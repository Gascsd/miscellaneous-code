#pragma once
#include <vector>
namespace zht
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)//less��greater��Ҫʵ�ֵľ���һ���Ƚϣ���������ķ���ֵ��bool����
		{
			return x < y;
		}
	};
	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child)
		{
			Compare cmp;//ʵ�����º���
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (cmp(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					//���ӵ���
					child = parent;
					parent = (child - 1) / 2;
				}
			}
		}
		void adjust_down(size_t parent)
		{
			Compare cmp;//ʵ�����º���
			int minchild = 2 * parent + 1;
			while (minchild < _con.size())
			{
				if (minchild + 1 < _cin.size() && cmp(_con[minchild], con[minchild + 1]))//ʹ�÷º����ҵ������������ӽڵ�
				{
					minchild++;
				}
				if (cmp(_con[parent], _con[minchild]))//�ж��Ƿ�����ѽṹ
				{
					std::swap(_con[parent], _con[minchild]);

					parent = minchild;
					minchild = 2 * parent + 1;
				}
			}
		}
		//�޲εĹ��캯��
		priority_queue() {}
		//���������乹��
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			_con(first, last)
		{
			//�����һ�����ڵ��λ�ÿ�ʼ���µ������ѣ�Ч�����
			for (int i = (_con.size() - 1 - 1) / 2; i <= 0; --i)
			{
				adjust_down(i);
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);//β������
			adjust_up(_con.size() - 1);//���ϵ����ѽṹ
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);//�����Ѷ��Ͷ������һ��Ԫ��
			_con.pop_back;//����βɾ
			adjust_down(0);//���µ����ѽṹ
		}
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top() const
		{
			return _con[0];
		}
	private:
		Container _con;
	}; 
}