#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void Test_unordered_map()
{
    unordered_map<string, int> countMap;
    string arr[] = { "苹果", "西瓜", "香蕉","苹果", "西瓜", "西瓜"};
    for(const auto& str : arr)
    {
        //countMap[str]++;
        auto it = countMap.find(str);
        if(it == countMap.end())
        {
            countMap.insert(make_pair(str, 1));
        }
        else
        {
            it->second++;
        }
    }
    for(const auto& kv : countMap)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
    cout << endl;
}
void Test_unordered_set()
{
    unordered_set<int> us;
    us.insert(10);
    us.insert(2);
    us.insert(4);
    us.insert(5);
    us.insert(3);
    us.insert(1);
    us.insert(10);
    unordered_set<int>::iterator it = us.begin();
    while(it != us.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
void Test_efficient()
{
	const size_t N = 1000000;//测试的数据个数
    //构造两个数组，一个有序一个无序，用于测试
	vector<int> SortV;
    vector<int> UnsortV;
	SortV.reserve(N);
	UnsortV.reserve(N);
	srand(time(0));
	for (int i = 0; i < N; ++i)
	{
		UnsortV.push_back(rand());
        SortV.push_back(i);
	}
    //开始测试
    unordered_set<int> SortUs;
    unordered_set<int> UnsortUs;
	set<int> SortS;
	set<int> UnsortS;
    cout << "有序插入效率对比" << endl;
	size_t begin1 = clock();
	for (auto e : SortV)
	{
		SortS.insert(e);
	}
	size_t end1 = clock();
	cout << "set insert sorted:" << end1 - begin1 << endl;
	size_t begin2 = clock();
	for (auto e : SortV)
	{
		SortUs.insert(e);
	}
	size_t end2 = clock();
	cout << "unordered_set insert sorted:" << end2 - begin2 << endl;
    cout << "无序插入效率对比" << endl;
	size_t begin3 = clock();
	for (auto e : UnsortV)
	{
		UnsortS.insert(e);
	}
	size_t end3 = clock();
	cout << "set insert unsort:" << end3 - begin3 << endl;
	size_t begin4 = clock();
	for (auto e : UnsortV)
	{
		UnsortUs.insert(e);
	}
	size_t end4 = clock();
	cout << "unordered_set insert unsort:" << end4 - begin4 << endl;
	
    cout << "有序查找效率对比" << endl;
    size_t begin5 = clock();
	for (auto e : SortV)
	{
		SortS.find(e);
	}
	size_t end5 = clock();
	cout << "set find sorted:" << end5 - begin5 << endl;
	size_t begin6 = clock();
	for (auto e : SortV)
	{
		SortUs.find(e);
	}
	size_t end6 = clock();
	cout << "unordered_set find sorted:" << end6 - begin6 << endl;
    cout << "无序查找效率对比" << endl;
    size_t begin7 = clock();
	for (auto e : UnsortV)
	{
		UnsortS.find(e);
	}
	size_t end7 = clock();
	cout << "set find unsorted:" << end7 - begin7 << endl;
	size_t begin8 = clock();
	for (auto e : UnsortV)
	{
		UnsortUs.find(e);
	}
	size_t end8 = clock();
	cout << "unordered_set find unsorted:" << end8 - begin8 << endl;
    cout << "有序删除效率对比" << endl;
	size_t begin9 = clock();
	for (auto e : SortV)
	{
		SortS.erase(e);
	}
	size_t end9 = clock();
	cout << "set erase sorted:" << end9 - begin9 << endl;
	size_t begin10 = clock();
	for (auto e : SortV)
	{
		SortUs.erase(e);
	}
	size_t end10 = clock();
	cout << "unordered_set erase:" << end10 - begin10 << endl;
    cout << "无序删除效率对比" << endl;
    size_t begin11 = clock();
	for (auto e : UnsortV)
	{
		UnsortS.erase(e);
	}
	size_t end11 = clock();
	cout << "set erase sorted:" << end11 - begin11 << endl;
	size_t begin12 = clock();
	for (auto e : UnsortV)
	{
		UnsortUs.erase(e);
	}
	size_t end12 = clock();
	cout << "unordered_set erase:" << end12 - begin12 << endl;
}
int main()
{
    // Test_unordered_set();
    // Test_unordered_map();
    Test_efficient();
    return 0;
}