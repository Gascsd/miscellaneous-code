#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>

using namespace std;

enum
{
	EXIT,//�˳� 0
	SOLVE//���������� 1
};

class Solution {
public:
	void DFS(vector<vector<pair<int, int>>>& allRet, vector<pair<int, int>>& curRet, int curRow, int n)
	{
		//���ÿһ�ж�û�г�ͻ������һ�ֿ��еķ���
		if (curRow == n)
		{
			allRet.push_back(curRet);
			return;
		}
		
		for (int i = 0; i < n; i++)
		{
			//ȷ����ǰ�е�ÿ��λ���Ƿ���Ѿ�ȷ����λ���г�ͻ
			if (isValidPos(curRet, curRow, i))
			{
				curRet.push_back(make_pair(curRow, i));
				//������һ��
				DFS(allRet, curRet, curRow + 1, n);
				//����
				curRet.pop_back();
			}
		}
	}

	bool isValidPos(vector<pair<int, int>>& curRet, int row, int col)
	{
		for (pair<int, int> pos : curRet)
		{
			if (pos.second == col || pos.first + pos.second == row + col
				|| pos.first - pos.second == row - col)//�ж��кͶԽ����Ƿ���������
				return false;
		}
		return true;
	}

	vector<vector<string>> transResult(vector<vector<pair<int, int>>>& allRet, int n)
	{
		vector<vector<string>> allMat;
		//���з���
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
			//һ�ַ��������лʺ��λ��
			for (pair<int, int> pos : curRet)
			{
				//ת�����ڻʺ��λ�ã�ʹ��ӡ�������ÿ�
				int second = 0;
				if (pos.second == 0)
				{
					second = pos.second;
				}
				else
				{
					second = 2 * pos.second;
				}
				//��������
				curMat[pos.first][second] = 'Q';
			}
			allMat.push_back(curMat);
		}
		return allMat;
	}

	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<pair<int, int>>> allMat;//���еĽ������
		vector<pair<int, int>> curRet;//��ǰ�Ľ������
		DFS(allMat, curRet, 0, n);
		return transResult(allMat, n);
	}
};

void menu()
{
	cout << "*****n�ʺ������������ʾ *****" << endl;
	cout << "******************************" << endl;
	cout << "*********1. ����ϵͳ *********" << endl;
	cout << "*********0. �˳�     *********" << endl;
	cout << "******************************" << endl;
}
bool isVaildInput(string str)//�ж������Ƿ�Ϸ�
{
	//���str���Ƿ�ֻ�������ֻ�����-�����֣���Ϊ�û�Ҳ�������븺��
	if (str[0] == '-')//����Ϊ����
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
		cout << "������ʺ������";
		cin >> str;
		if (!isVaildInput(str))
		{
			cout << "�����ʽ��������������" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			n = stoi(str);//��strת��Ϊint����
			cout << "�ʺ�ĸ���Ϊ��" << n << endl;
			if (n == 0)
			{
				cout << "������0�ʺ�����" << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << n << "�ʺ�Ľ�Ϊ��" << endl;
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
			cout << n << "�ʺ�Ľ�һ����" << count / n << "��" << endl;
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
		cout << "������ѡ��";
		cin >> str;
		if (isVaildInput(str))
		{
			input = stoi(str);//��strת��Ϊint����
			switch (input)
			{
			case EXIT:
				cout << "�˳�" << endl;
				exit(0);
			case SOLVE:
				solve();
				break;
			default:
				cout << "�����������������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "�����ʽ��������������" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}
