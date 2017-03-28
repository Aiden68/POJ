#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
void quickFind(int arr[],int start, int end, int k)
{
	int i = start;
	int j = end;
	int key = arr[start];
	while(i < j)
	{
		while(i < j && arr[j] > key)
			j--;
		arr[i] = arr[j];
		while(i < j && arr[i] < key)
			i++;
		arr[j] = arr[i];
	}
	arr[i] = key;
	if(end - i + 1 ==  k)
	{
		sort(arr + i, arr + n);
		return;
	}
	else if(end - i  + 1 > k)
	{
		quickFind(arr, i + 1, end, k);
	}
	else
	{
		quickFind(arr, start, i - 1, k - end - 1 + i);
	}
}

int main()
{
	int arr[100010] = { 0 };
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	quickFind(arr, 0, n - 1, k);
	for(int i = n - 1; i >= n - k; i--)
		printf("%d\n", arr[i]);
	return 0;
}