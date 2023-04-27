#pragma once
#include <vector>
namespace zht
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)//less和greater需要实现的就是一个比较，所以这里的返回值是bool类型
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
			Compare cmp;//实例化仿函数
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (cmp(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					//父子迭代
					child = parent;
					parent = (child - 1) / 2;
				}
			}
		}
		void adjust_down(size_t parent)
		{
			Compare cmp;//实例化仿函数
			int minchild = 2 * parent + 1;
			while (minchild < _con.size())
			{
				if (minchild + 1 < _cin.size() && cmp(_con[minchild], con[minchild + 1]))//使用仿函数找到符合条件的子节点
				{
					minchild++;
				}
				if (cmp(_con[parent], _con[minchild]))//判断是否满足堆结构
				{
					std::swap(_con[parent], _con[minchild]);

					parent = minchild;
					minchild = 2 * parent + 1;
				}
			}
		}
		//无参的构造函数
		priority_queue() {}
		//迭代器区间构造
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			_con(first, last)
		{
			//从最后一个父节点的位置开始向下调整建堆，效率最高
			for (int i = (_con.size() - 1 - 1) / 2; i <= 0; --i)
			{
				adjust_down(i);
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);//尾插数据
			adjust_up(_con.size() - 1);//向上调整堆结构
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);//交换堆顶和堆内最后一个元素
			_con.pop_back;//容器尾删
			adjust_down(0);//向下调整堆结构
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