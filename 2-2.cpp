#include<iostream>
#include<cmath>
using namespace std;

void solve(int& n)
{
	int i = 0;
	while (pow(2.0, i) <= n)
		i++;
	n -= (pow(2.0, --i));
	printf("2");
	if (i == 0)
	{
		printf("(0)");
	}
	else if (i != 1)
	{
		printf("(");
		solve(i);
		printf(")");
	}
	if (n != 0)
	{
		printf("+");
		solve(n);
	}
	return;
}

int main()
{
	int arr[5] = {10, 9, 15, 3, 2};
	int n;
	cin >> n;
	solve(n);
	return 0;
}