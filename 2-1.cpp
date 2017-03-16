
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int visit[10];
string temp;
vector<string> result;
void solve(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (visit[i] == 0)
		{
			temp += str[i];
			if (temp.size() == str.size())
			{
				result.push_back(temp);
			}
			visit[i] = 1;
			solve(str);
			temp.erase(temp.size() - 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	string str;
	cin >> str;
	solve(str);
	for (int i = 0; i < result.size(); i++)
	{
		printf("%s\n", result[i].c_str());
	}
	return 0;
}