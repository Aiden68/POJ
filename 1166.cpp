#include<iostream>
using namespace std;

char *moveo[9] = { "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI" };

void moveClock(int clock[], int num, int times, int operationRecord[])
{
	operationRecord[num] = times;
	for (int i = 0; moveo[num][i]; i++)
	{
		int temp = moveo[num][i] - 'A';
		clock[temp] = (clock[temp] + times) % 4;
	}
}

int main()
{
	int clock[9] = { 0 };
	int operationRecord[9] = { 0 };
	int min = 1 << 30;
	for (int i = 0; i < 9; i++)
	{
		cin >> clock[i];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int tor[9] = { 0 };
				int tclock[9] = { 0 };
				for (int v = 0; v < 9; v++)
					tclock[v] = clock[v];
				int cnt = i + j + k;
				moveClock(tclock, 0, i, tor);
				moveClock(tclock, 1, j, tor);
				moveClock(tclock, 2, k, tor);
				for (int x = 3; x < 9; x++)
				{
					if (tclock[x - 3] != 0 && x != 7)
					{
						cnt += (4 - tclock[x - 3]);
						moveClock(tclock, x, 4 - tclock[x - 3], tor);
					}
					else if (x == 7 && tclock[x - 1] != 0)
					{
						cnt += (4 - tclock[x - 1]);
						moveClock(tclock, x, 4 - tclock[x - 1], tor);
					}
				}
				int flag = 0;
				for (int x = 0; x < 9; x++)
				{
					if (tclock[x] != 0)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					if (min > cnt)
					{
						min = cnt;
						for (int z = 0; z < 9; z++)
							operationRecord[z] = tor[z];
					}
				}
			}
		}
	}
	int space = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < operationRecord[i]; j++)
		{
			if (space == 0)
				space++;
			else
				cout<<" ";
			cout << i + 1;
		}
	}
	return 0;
}