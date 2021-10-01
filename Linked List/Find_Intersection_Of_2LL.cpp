

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    //M1 Uses extra space : Stack based approach.
    // if( headA==NULL || headB==NULL)
    //     return NULL;
    // stack <ListNode*> l1;
    // stack<ListNode*>l2;
    // ListNode * p=headA;
    // while(p)
    // {
    //     l1.push(p);
    //     p=p->next;
    // }
    // p= headB;
    // while(p)
    // {
    //     l2.push(p);
    //     p=p->next;
    // }
    // bool prevNodeSame=false;
    // ListNode* prevNode=NULL;
    // while( !l1.empty() && !l2.empty())
    // {
    //     ListNode* x=l1.top();
    //     l1.pop();
    //     ListNode* y=l2.top();
    //     l2.pop();
    //     if(x==y)
    //     {
    //         prevNode=x;
    //         prevNodeSame=true;
    //     }
    //     if(prevNodeSame==true && x!=y)
    //         return prevNode;
    // }
    // return prevNode;

    //M2: Optimal method which iterates each list once untill a common vertex is found.
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL)
        return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == p2)
            return p1;
        if (p1 == NULL)
            p1 = headB;
        if (p2 == NULL)
            p2 = headA;
    }
    return p1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode *headA = NULL, *headB = NULL;
    // Generate both Linkedlists.
    // Call getIntersectionNode(ListNode *headA, ListNode *headB)
    // Function returns the intersection node.
    return 0;
}