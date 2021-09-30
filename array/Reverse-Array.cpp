#include<iostream>
using namespace std;
void ReverseArray(int arr[], int start, int end)
{
    while(start<end){
        //Transfer the value of starting element in a Temp Var.
        int temp = arr[start];
        // Put the Last Value of Array to the Beginning
        arr[start] = arr [end];
        // Put the Starting value (stored in temp) to the end.
        arr [end] = temp;
        start++;
        end--;
    }
}
void printArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    ReverseArray(arr,0,n-1);
    cout<<"Reversed Array is:"<<endl;
    printArray(arr,n);
    return 0;

}