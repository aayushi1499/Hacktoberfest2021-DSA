#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;

}*head=NULL;
void create()
{
    int n,i,l;
    char c ;
    struct node* temp,*newnode,*ptr;

    printf("Enter the number of nodes you want to enter\n");
    scanf("%d",&n);
    printf("Do you want to create a loop?");
    scanf("%c",&c);
    if(c=='y')
    {
        printf("Enter the position where you want to create a loop");
        scanf("%d",&l);

    }

    for(i=1;i<=n;i++)
    {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter data for node %d:",i);
            scanf("%d",&newnode->data);
            if(head==NULL)
            {
                 head=(struct node*)malloc(sizeof(struct node));
                head=newnode;
                head->next=NULL;
                temp=head;
            }
            else{

                newnode->next=NULL;
                temp->next=newnode;
                temp=temp->next;


            }
}
ptr=head;
for(i=1;i<l;i++)
{
    ptr=ptr->next;

}
if(c=='y')
{
 temp->next=ptr;
}

}
void traverse()
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("\nThe element is %d",temp->data);
        temp=temp->next;
    }


}
int main()
{
    int choice;
    do{
        printf("\n1.Create\n");
        printf("2.Display\n");
        printf("3.exit\n");
        printf("Enter the choice you want to enter\n");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:
        create();
        continue;
    case 2:
        traverse();
        continue;

        default:
        printf("Enter a valid choice");
        continue;




    }}while(choice!=3);






 return 0;


}


