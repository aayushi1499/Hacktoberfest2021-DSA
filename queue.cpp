/*Implementing Queue using arrays*/

#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

class Queue{
    public:
    int front; // it will store the starting index of queue (array)
    int rear;  //it will store ending index of queue
    int q[MAXSIZE];
    Queue() //Constructor
    {
        front= -1;  //as queue is empty initialising front nad rear with -1
        rear= -1;
    }
};
//function to check is queue empty?
int isqempty(Queue* qu)
{
   if((qu->front==(-1)) && (qu->rear==(-1)))
   return true;
   else
   return false;
}
//to add element in queue
void Enqueue(Queue* qu, int val)
{
    if(qu->rear==(MAXSIZE-1))
    cout<<"queue is full"<<endl;
    else{
    if(qu->front==-1)
    qu->front++;
    
    qu->rear++;
    qu->q[qu->rear]=val;}
}
//to remove element from queue
void Dequeue(Queue* qu)
{
    if((qu->front==(-1))||((qu->front)>(qu->rear)))
    cout<<"No element to remove from queue"<<endl;
    else
    qu->front++;
}
//to print queue
void printq(Queue qu)
{
    if(qu.front==(-1))
    cout<<"Queue is empty"<<endl;
    else
    {
        for(int i=qu.front;i<=qu.rear;i++)
        cout<<qu.q[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    
    Queue qu;

    printq(qu); //queue is empty

    Enqueue(&qu,1);
    Enqueue(&qu,2);
    Enqueue(&qu,3);
    printq(qu); //queue with three elements
}