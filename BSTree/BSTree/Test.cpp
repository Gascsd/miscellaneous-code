#include "BSTree.h"
#include <string>
#include <vector>
#include <map>
void Test_Spell()
{
	zht::BSTree<string> chack;
	//创建一个词库，在实际应用中可以直接导入
	chack.Insert("apple");
	chack.Insert("beside");
	chack.Insert("car");
	chack.Insert("desktop");
	chack.Insert("erase");
	chack.Insert("find");
	chack.Insert("group");
	vector<string> word = { "apple", "beside", "cccd", "force" , "find" };
	cout << "拼写错误的单词有：";
	for (auto e : word)
	{
		if (! chack.Find(e))
		{
			cout << e << " ";
		}
	}
	cout << endl;
}

void TestTranslate()
{
	map<string, string> dict;
	//创建词库
	//dict.insert("string", "字符串");
	//dict.insert("tree", "树");
	//dict.insert("left", "左边、剩余");
	//dict.insert("right", "右边");
	//dict.insert("sort", "排序");
	//string word;
	//while (cin >> word)
	//{
	//	map<string, string>::iterator ret = dict.find(word);
	//	cout << ret->second << endl;

	//}
}

int main()
{
	//zht::Test1();
	//Test_Spell();
	TestTranslate();
	return 0;
}