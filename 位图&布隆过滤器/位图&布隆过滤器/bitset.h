#pragma once
#include <vector>
using namespace std;


namespace zht
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			//���ڵײ�洢ʹ�õ���vector<char>������һ��char�п��Դ��8�����ݣ���ΪN��Ҫ����3λ������ΪN��һ����8�ı�����������Ҫ�ٿ�һ��char�Ĵ�С���ڴ洢��������
			_bit.resize((N >> 3) + 1, 0);
		}
		void set(size_t x)//����ʾ��λ��ֵ��Ϊ1
		{
			//i��ʾ�ڵڼ���char�У�j��ʾ�����char�е�ƫ����
			int i = x / 8;
			int j = x % 8;
			_bit[i] |= (1 << j);
		}
		void reset(size_t x) // ����ʾ��λ��ֵ��Ϊ1
		{
			//i��ʾ�ڵڼ���char�У�j��ʾ�����char�е�ƫ����
			int i = x / 8;
			int j = x % 8;
			_bit[i] &= ~(1 << j);
		}
		bool test(size_t x)
		{
			int i = x / 8;
			int j = x % 8;
			return _bit[i] & (1 << j);
		}
	private:
		vector<char> _bit;
	};

	void test_bitset()
	{
		bitset<0xffffffff> bs1;
		bs1.set(111111);
		bs1.set(111);
		bs1.set(1311);
		bs1.set(651);
		bs1.set(171);
		cout << bs1.test(111111) << endl;
		cout << bs1.test(111) << endl;
		cout << bs1.test(112) << endl;
	}
	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x)
		{
			if (!_bs1.test(x) && !_bs2.test(x))//00
			{
				_bs2.set(x);//���01
			}
			else if (!_bs1.test(x) && _bs2.test(x))//01
			{
				//���10
				_bs1.set(x);
				_bs2.reset(x);
			}
			// 10 ����
		}
		void outputOnce()//��ӡֻ����һ�ε���
		{
			for (size_t i = 0; i < N; ++i)
			{
				if (!_bs1.test(i) && _bs2.test(i))
				{
					cout << i << endl;
				}
			}
			cout << endl;
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
	void test_twobitset()
	{
		twobitset<100> tbs;
		int a[] = { 2,4,56,67,6,34,1,5,6,4,3,33,5 };
		for (auto e : a)
		{
			tbs.set(e);
		}
		tbs.outputOnce();
	}
	//template <size_t N, size_t X = 5, class K = string,
	//	class HashFunc1,
	//	class HashFunc2,
	//	class HashFunc3>
	//class BloomFilter
	//{
	//public:
	//	void set(const K& key)
	//	{
	//		//�ֱ�������Ӧ��λ�ã�Ȼ����н���λ�õ�ֵ��Ϊ1����
	//		size_t hash1 = HashFunc1()(key) % (N * X);
	//		size_t hash2 = HashFunc2()(key) % (N * X);
	//		size_t hash3 = HashFunc3()(key) % (N * X);
	//		_bs.set(hash1);
	//		_bs.set(hash2);
	//		_bs.set(hash3);
	//	}
	//	bool test(const K& key)
	//	{
	//		size_t hash1 = HashFunc1()(key) % (N * X);
	//		if (!_bs.test(hash1))
	//			return false;
	//		size_t hash2 = HashFunc1()(key) % (N * X);
	//		if (!_bs.test(hash2))
	//			return false;
	//		size_t hash3 = HashFunc3()(key) % (N * X);
	//		if (!_bs.test(hash3))
	//			return false;
	//		return true;
	//	}
	//private:
	//	bitset<N* X> _bs;
	//};
}

