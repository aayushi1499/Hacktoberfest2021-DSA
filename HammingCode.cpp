#include<iostream>
#include<math.h>
using namespace std;
int transmit[100];
int calculateRedudantBits(int m)
{
    int i;
    i = 0;
    while(pow(2,i) < m + i + 1)             /*2^r ≥ m + r + 1, where, r = redundant bit, m = data bit*/
    {
        i = i+1;
    }
    return i;
}

void appendData(int m, int data[], int length)
{
    int total = m + length;
    int j =0;
    int k =length-1;
    for(int i =0; i<total;i++)
    {
        if(i == (pow(2,j) - 1))         /*(Powers of 2 - 1,2,4,8,16)*/
        {
            j = j+1;
            transmit[i] = 2;
        }
        else
        {
            transmit[i] = data[k];
            k = k-1;
        }
    }
}

int calculateParity(int r,int m, int length)
{ //rth position
int index; 
int sum = 0;
    for(int i =0; i <m+length;i++)
    {
        index = i+1;
        for(int j = 0; j<r; j++)
        {
            index = index >> 1;
        }
        if(index&1==1)
        {
            sum = sum + transmit[i];
        }
    }
    if(sum%2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int length;
    cout << "Enter the length of data to be transmitted:" ;
    cin >> length;
    int data[length];
    cout << "Enter the data to be transmitted:" ;
    for(int i =0; i<length;i++)
    {
        cin >> data[i];
    }
    int m = calculateRedudantBits(length);
    appendData(m,data,length);
    for(int i =m+length-1; i>=0;i--)
    {
        cout <<  transmit[i] << " ";
    }
    cout << endl;
    for(int i=0;i<m;i++)
    {
        int random = (pow(2,i) - 1);
        transmit[random] = calculateParity(i,m,length);
    }
    cout << "Transmitted Data is: ";
    for(int i =m+length-1; i>=0;i--)
    {
        cout <<  transmit[i] << " ";
    }
    return 0;
}
