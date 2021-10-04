#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high, bool(*cmp_function)(int, int))
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//if (arr[j] < pivot)
		if (cmp_function(arr[j], pivot))
        {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high, bool(*cmp_function)(int, int))
{
	if (low < high)
	{
		int pi = partition(arr, low, high, cmp_function);
		quickSort(arr, low, pi - 1, cmp_function);
		quickSort(arr, pi + 1, high, cmp_function);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool desc(int a, int b) {
  if(a > b)
    return(true);

  return(false);
}

bool asc(int a, int b) {
  if(a < b)
    return(true);
    
  return(false);
}

int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
  
	quickSort(arr, 0, n - 1, asc);
	cout << "Asc. sorted array: \n";
    printArray(arr, n);
  
    quickSort(arr, 0, n - 1, desc);
	cout << "Desc. sorted array: \n";
	printArray(arr, n);
	return 0;
}
