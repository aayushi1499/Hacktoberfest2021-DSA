#include <bits/stdc++.h>
using namespace std;
class listnode {
   public:
      int data;
   listnode * next;
};
// Find the length of the linked list
int count(listnode * head) {
   int count = 0;
   while (head != NULL) {
      count++;
      head = head -> next;
   }
   return count;
}
//Function to get the common point of two linked list
int commonPoint(listnode * headA, listnode * headB) {
   int len1 = count(headA);
   int len2 = count(headB);
   listnode * p1 = headA;
   listnode * p2 = headB;
   if (len1 > len2) {
      for (int i = 0; i < len1 - len2; ++i) {
         p1 = p1 -> next;
      }
   }
   if (len1 < len2) {
      for (int i = 0; i < len2 - len1; ++i) {
         p2 = p2 -> next;
      }
   }
   while (p1 != NULL and p2 != NULL) {
      if (p1 == p2) {
         return p1 -> data;
      }
      p1 = p1 -> next;
      p2 = p2 -> next;
   }
   return -1;
}
int main() {
   listnode * head;
   listnode * headA = new listnode();
   headA -> data = 5;
   listnode * headB = new listnode();
   headB -> data = 4;
   head = new listnode();
   head -> data = 9;
   headB -> next = head;
   head = new listnode();
   head -> data = 2;
   headB -> next -> next = head;
   head = new listnode();
   head -> data = 7;
   headA -> next = head;
   headB -> next -> next -> next = head;
   head = new listnode();
   head -> data = 3;
   headA -> next -> next = head;
   headA -> next -> next -> next = NULL;
   cout << commonPoint(headA, headB) << endl;
}
