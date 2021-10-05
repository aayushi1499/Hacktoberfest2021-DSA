#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node*deleteatbeg(struct Node*head)
{
    struct Node*ptr = head;
    head=head->next;
    ptr->next=NULL;
    free(ptr);
    return head;
}
struct Node*deleteatbet(struct Node*head,int n)
{
    struct Node*ptr = head;
    while ((n-1)>0)
    {
        ptr=ptr->next;
        n--;
    }
    struct Node*qtr=ptr->next;
    ptr->next=qtr->next;
    free(qtr);
    return head;
}
struct Node*deleteatend(struct Node*head)
{
    struct Node*ptr = head;
    while ((ptr->next)->next!=NULL)
        ptr=ptr->next;
    struct Node*qtr=ptr->next;
    ptr->next=NULL;
    free(qtr);
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
    printf("Linked list before Deletion :-\n");
    linkedListTraversal(head);
    printf("\nLinked list after Deleting Element from beginning :-\n");
    head=deleteatbeg(head);
    linkedListTraversal(head);
    printf("\nLinked list after Deleting at given node :-\n");
    head=deleteatbet(head,1);
    linkedListTraversal(head);
    printf("\nLinked list after deleting at end :-\n");
    head=deleteatend(head);
    linkedListTraversal(head);
    return 0;
}
