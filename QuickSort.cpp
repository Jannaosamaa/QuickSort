#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];	// pivot (Element to be placed at right position)
	int i = (low - 1);		//Index of smaller elementand indicates the right position of pivot found so far
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)	 // If current element is smaller than the pivot
		{
			i++;			// increment index of smaller element
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[high], arr[i + 1]);
	return (i + 1);
}
void QuickSort(int arr[], int low, int high)
{
	int pi;
	if (low < high)
	{
		pi = partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

void printArr(int arr[], int size)
{
	cout << "Array is [";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "	";
	}
	cout << "]" << endl;
}

int main()
{
	int UnsortedArray[7] = { 2 , 19 , 1 ,3 , 5 , 6 ,4 };
	printArr(UnsortedArray, 7);
	QuickSort(UnsortedArray, 0, 6);
	printArr(UnsortedArray, 7);
}