// A C++ program to sort an array in wave form using
#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sortInWave(int arr[], int n)
{
	// Sort the input array
	sort(arr, arr+n);

	// Swap adjacent elements
	for (int i=0; i<n-1; i += 2)
		swap(&arr[i], &arr[i+1]);
}

int main()
{
	int arr[] = {15, 81, 40, 2, 1, 5, 26};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortInWave(arr, n);
	for (int i=0; i<n; i++)
	cout << arr[i] << " ";
	return 0;
}
