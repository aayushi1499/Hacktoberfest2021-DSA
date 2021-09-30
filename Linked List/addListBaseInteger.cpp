#include "SinglyLinkedList.h"

template <typename T> 
SinglyLinkedList<T> addListBasedInteger(SinglyLinkedList<T> list1, SinglyLinkedList<T> list2)
{
    int sum = 0, carry = 0, fullsum = 0; 
    SinglyLinkedList<T> list;
    Node<T> *current_list_1 = list1.getHead(), *current_list_2 = list2.getHead(), *current_result = NULL; 
    while(current_list_1 && current_list_2)
    {

        if(current_result == NULL)
        {
            fullsum = current_list_1->getData() + current_list_2->getData();
        }
        else 
        {
            fullsum = current_list_1->getData() + current_list_2->getData() + current_result->getData(); 
        }
        sum = fullsum % 10;
        carry = fullsum / 10;
        if(current_result == NULL)
        {
            current_result = new Node<T>(sum);
            list.setHead(current_result);
            current_result->setNext(new Node<T>(carry));
            current_result = current_result->getNext(); 
        }
        else 
        {
            current_result->setData(sum);
            current_result->setNext(new Node<T>(carry));
            current_result = current_result->getNext(); 
        }
        current_list_1 = current_list_1->getNext();
        current_list_2 = current_list_2->getNext(); 
    }

    while(current_list_1)
    {
        fullsum = current_list_1->getData() + current_result->getData();
        sum = fullsum % 10;
        carry = fullsum / 10; 
        current_result->setData(sum);
        current_result->setNext(new Node<T>(carry)); 
        current_result = current_result->getNext(); 
        current_list_1 = current_list_1->getNext(); 
    }

    while(current_list_2)
    {

        fullsum = current_list_2->getData() + current_result->getData();
        sum = fullsum % 10;
        carry = fullsum / 10;
        current_result->setData(sum);
        current_result->setNext(new Node<T>(carry));
        current_result = current_result->getNext(); 
        current_list_2 = current_list_2->getNext(); 
    }

    return list; 
}

int main(int argc, char* argv[]) {
    SinglyLinkedList<int> list1, list2, result;
    list1.push_back(3);
    list1.push_back(1);
    list1.push_back(4);
    list2.push_back(7); 
    list2.push_back(0);
    list2.push_back(9);
    list1.print();
    list2.print(); 
    result = addListBasedInteger(list1, list2);
    result.print(); 

    return 0; 
}
