/* add c++ headers if necessary*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

// To print array of length=size
void printArray(int array[], int size)    
{
  int i;
  for (i=0; i < size; i++)
    cout<<array[i]<<"\t";
  cout<<endl;
}

// To swap two elements
void swap(int* a, int* b)    
{
  int t = *a;
  *a = *b;
  *b = t;
}

/* This function takes last element as pivot, and places all smaller
   elements to left of pivot and all greater elements to right of pivot */
int partition (int array[], int low, int high)
{
  int pivot = array[high];    // pivot
  int i = (low - 1);  // Index of smaller element
  int j;

  for (j = low; j <= high- 1; j++)
  {
    if (array[j] <= pivot)
    {
      i++;            // increment index of smaller element
      swap(&array[i], &array[j]);    // shift all lesser elements in left half
    }
  }
  swap(&array[i + 1], &array[high]);    // place pivot element at end of smaller elements
  return (i + 1);    // the index of pivot element
}

// Recursive function to sort array with quicksort
void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pivot_index;
    pivot_index = partition(array, low, high);
    cout<<"Pivot element is "<<array[pivot_index]<<endl;
    cout<<"Array after pivot partitioning : \n";
    printArray(array,8);

    // Call quicksort() on left half and right half excluding
    // pivot element as it is already at proper position i.e.
    // between lesser and greater elements.
    quickSort(array, low, pivot_index - 1);
    quickSort(array, pivot_index + 1, high);
  }
}
int main()
{
  int array[] = {17, 13, 20, 16, 19, 24, 22, 21};
  int n = sizeof(array)/sizeof(array[0]);
  cout<<"Given array: \n";
  printArray(array, n);
  quickSort(array, 0, n-1);
  cout<<"Sorted array: \n";
  printArray(array, n);
  return 0;
}
