#include<iostream>
#include<string>
using namespace std;

char flipDigit(char digit)
{
	if(digit == '0')
		return '1';
	else
		return '0';
}

int solve(string& temp, string partern)
{
	int cnt = 0;
	for(int i = 1; i < temp.size(); i++)
	{
		if(temp[i - 1] != partern[i -1])
		{
			temp[i - 1] = flipDigit(temp[i - 1]);
			temp[i] = flipDigit(temp[i]);
			if(i + 1 < temp.size())
				temp[i + 1] = flipDigit(temp[i + 1]);
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	string source;
	string partern;
	cin >> source >> partern;
	string temp = source;
	int cnt = solve(temp, partern);
	if(temp != partern)
	{
		temp = source;
		temp[0] = flipDigit(temp[0]);
		temp[1] = flipDigit(temp[1]);
		cnt = solve(temp, partern);
		if(temp != partern)
			printf("impossible");
		else
			printf("%d", cnt + 1);
	}
	else
		printf("%d", cnt);
	return 0;
}