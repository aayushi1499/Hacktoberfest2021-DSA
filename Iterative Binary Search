#include<iostream>
using namespace std;
#define MAX 50
int Binary_Search(int arr[],int item,int size)
{
  int low=0,up=size-1,mid;
  while(low<=up)
  {
  mid=(low+up)/2;
  
  
   if(item>arr[mid])
  	low=mid+1;
  else if(item<arr[mid])
  	up=mid-1;
  else
  	return mid;
}
  	return-1;
};



int main()
{
	int size,i,arr[MAX],index,item;
	cout<<"Enter no of Elements"<<endl;
	cin>>size;
	cout<<"Enter elements in a sorted order"<<endl;
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"Array elements are \n"<<endl;
	for(i=0;i<=size;i++)
	{
		cout<<arr[i]<<endl;
	}
	cout<<"Enter the element to be searched"<<endl;
	cin>>item;
	index=Binary_Search(arr,item,size);
	if(index== -1)
		cout<<"Element not found in Array"<<endl;
	else
		cout<<item<<"Found at position"<<index<<endl;
	return 0;
}
