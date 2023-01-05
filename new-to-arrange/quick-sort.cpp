#include <bits/stdc++.h>
using namespace std;

int partitionAlgorithm(vector<int>& arr, int s, int e);
void quickSort(vector<int>& arr, int s, int e)
{
	// base step of recursion
	if (s >= e)
	{
		return;
	}

	// partition algorithm gives pivot
	int pivot = partitionAlgorithm(arr, s, e);

	// sort left part
	quickSort(arr, s, pivot-1);

	// sort right part
	quickSort(arr, pivot+1, e);
}

int partitionAlgorithm(vector<int>& arr, int s, int e)
{
	int count = 0;
	for (int i = s+1; i <= e; ++i)
	{
		if (arr[i] < arr[s])
		{
			count++;
		}
	}
	int p = s+count;
	swap(arr[s], arr[p]);
	while(s <= e)
	{
		if (arr[s] < arr[p])
		{
			s++;
		}
		if (arr[e] > arr[p])
		{
			e--;
		}
		swap(arr[s], arr[e]);
	}
	return p;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int s = 0, e = n-1;
	quickSort(arr, s, e);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}