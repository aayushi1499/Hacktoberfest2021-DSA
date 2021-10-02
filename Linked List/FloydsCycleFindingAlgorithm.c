#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct List
{
    int data;
    struct List* next ; 
    

};


bool Cycle(struct List* head)
{
    struct List* temp1, *temp2;
    temp2=head;
    temp1=head; 

    while(temp2)
    {
        temp2=temp2->next;
        if(temp1 == temp2)
        {
            return true;
        }
        temp1=temp1->next;
        if(temp2)   temp2=temp2->next;
    }
    return false;


}

struct List* Addatbeg(struct List* head, int data)
{
    struct List* temp = (struct List*)malloc(sizeof (struct List));
    temp->data=data;
    temp->next= head;
    return temp ; 


}



int main()
{
    
    struct List* head=NULL;

    head=Addatbeg(head,9);
    head=Addatbeg(head,12);
    head=Addatbeg(head,13);
    head=Addatbeg(head,1);
    
    struct List* temp = head;

    while (temp->next != NULL)
    {
        temp=temp->next;
    } 

    //temp->next= head;   //Case with cycle , uncomment to test 

    if(Cycle(head))
    {
        printf("Success ! \n");

    }

    else
    {
        printf("FAIL\n");
    }
   
    return 0 ;

}
