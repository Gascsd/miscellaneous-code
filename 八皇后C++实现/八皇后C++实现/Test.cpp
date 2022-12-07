#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>

using namespace std;

enum
{
	EXIT,//退出 0
	SOLVE//进入解决方案 1
};

class Solution {
public:
	void DFS(vector<vector<pair<int, int>>>& allRet, 
		vector<pair<int, int>>& curRet, int curRow, int n)
	{
		//如果每一行都没有冲突，则是一种可行的方案
		if (curRow == n)
		{
			allRet.push_back(curRet);
			return;
		}
		//确定当前行的每个位置是否和已经确定的位置有冲突
		for (int i = 0; i < n; i++)
		{
			if (isValidPos(curRet, curRow, i))
			{
				curRet.push_back(make_pair(curRow, i));
				//处理下一行
				DFS(allRet, curRet, curRow + 1, n);
				//回溯
				curRet.pop_back();
			}
		}
	}

	bool isValidPos(vector<pair<int, int>>& curRet, int row, int col)
	{
		for (pair<int, int> pos : curRet)
		{
			if (pos.second == col || pos.first + pos.second == row + col
				|| pos.first - pos.second == row - col)//判断列和对角线是否满足条件
				return false;
		}
		return true;
	}

	vector<vector<string>> transResult(vector<vector<pair<int, int>>>& allRet, int n)
	{
		vector<vector<string>> allMat;
		//所有方案
		for (vector<pair<int, int>> curRet : allRet)
		{
			vector<string> curMat(n, string(2 * n, '#'));
			for (int i = 0; i < n; i++)
			{
				for (int j = 1; j < 2*n; j += 2)
				{
					curMat[i][j] = ' ';
				}
			}
			//一种方案中所有皇后的位置
			for (pair<int, int> pos : curRet)
			{
				//转换调节皇后的位置，使打印出来更好看
				int second = 0;
				if (pos.second == 0)
				{
					second = pos.second;
				}
				else
				{
					second = 2 * pos.second;
				}
				//放入棋盘
				curMat[pos.first][second] = '*';
			}
			allMat.push_back(curMat);
		}
		return allMat;
	}

	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<pair<int, int>>> allMat;
		vector<pair<int, int>> curRet;
		DFS(allMat, curRet, 0, n);
		return transResult(allMat, n);
	}
};

void menu()
{
	cout << "*****n皇后问题求解与演示 *****" << endl;
	cout << "******************************" << endl;
	cout << "*********1. 进入系统 *********" << endl;
	cout << "*********0. 退出     *********" << endl;
	cout << "******************************" << endl;
}
bool isVaildInput(string str)//判断输入是否合法
{
	//检测str中是否只含有数字或者是-和数字，因为用户也可能输入负数
	if (str[0] == '-')//输入为负数
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				continue;
			else
			{
				return false;
			}
		}
	}
	return true;
}
void solve()
{
	while (1)
	{
		int n = 0;
		string str;
		cout << "请输入皇后个数：";
		cin >> str;
		if (!isVaildInput(str))
		{
			cout << "输入格式有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			n = stoi(str);//将str转换为int类型
			cout << "皇后的个数为：" << n << endl;
			if (n == 0)
			{
				cout << "不存在0皇后的情况" << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << n << "皇后的解为：" << endl;
			vector<vector<string>> allMat = Solution().solveNQueens(n);
			int count = 0;
			for (int i = 0; i != allMat.size(); i++)
			{
				for (int j = 0; j != allMat[0].size(); j++)
				{
					cout << allMat[i][j] << endl;
					count++;
				}
				cout << endl;
			}
			cout << n << "皇后的解一共有" << count / n << "种" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


int main()
{
	while (1)
	{
		int input = 0;
		menu();
		string str;
		cout << "请输入选择：";
		cin >> str;
		if (isVaildInput(str))
		{
			input = stoi(str);//将str转换为int类型
			switch (input)
			{
			case EXIT:
				cout << "退出" << endl;
				exit(0);
			case SOLVE:
				solve();
				break;
			default:
				cout << "输入错误，请重新输入" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "输入格式有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}

	}
	return 0;
}
