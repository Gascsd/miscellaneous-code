#include "BSTree.h"
#include <string>
#include <vector>
#include <map>
void Test_Spell()
{
	zht::BSTree<string> chack;
	//����һ���ʿ⣬��ʵ��Ӧ���п���ֱ�ӵ���
	chack.Insert("apple");
	chack.Insert("beside");
	chack.Insert("car");
	chack.Insert("desktop");
	chack.Insert("erase");
	chack.Insert("find");
	chack.Insert("group");
	vector<string> word = { "apple", "beside", "cccd", "force" , "find" };
	cout << "ƴд����ĵ����У�";
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
	//�����ʿ�
	//dict.insert("string", "�ַ���");
	//dict.insert("tree", "��");
	//dict.insert("left", "��ߡ�ʣ��");
	//dict.insert("right", "�ұ�");
	//dict.insert("sort", "����");
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