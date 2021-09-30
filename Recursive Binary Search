#include<iostream>
using namespace std;
#define MAX 50
int Binary_Search(int arr[],int item,int low,int up)
{
  int mid;
  if(low>up)
  	return -1;
  mid=(low+up)/2;
   if(item<arr[mid])
  	Binary_Search(arr,item,low,mid-1);
  else if(item>arr[mid])
  	Binary_Search(arr,item,mid+1,up);
  else
  	return mid;
}



int main()
{
	int size,i,arr[MAX],index,item,low,up;
	
	cout<<"Enter no of Elements"<<endl;
	cin>>size;
	cout<<"Enter elements in a sorted order"<<endl;
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"Array elements are \n"<<endl;
	for(i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
	}
	low=0,up=size-1;
	cout<<"Enter the element to be searched"<<endl;
	cin>>item;
	index=Binary_Search(arr,item,low,up);
	if(index== -1)
		cout<<"Element not found in Array"<<endl;
	else
		cout<<item<<"Found at position"<<index<<endl;
	return 0;
}
