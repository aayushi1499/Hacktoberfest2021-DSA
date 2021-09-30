#ifndef SINGLYLINKEDLIST_H 
#define SINGLYLINKEDLIST_H 
#include <iostream> 
#include <cstdlib> 
#include <vector> 
#include <stdexcept> 

using namespace std; 

/**
 * 
 * @name : Node.
 * 
*/

template <typename T> 
class Node {
    public:
        Node();
        Node(T data);
        T getData() const;
        Node<T> *getNext() const;
        bool setData(T data);
        bool setNext(Node<T> *next);
        bool print() const; 

    private:
        T key;
        Node<T> *next; 
};

template <typename T> 
Node<T>::Node()
{
    this->next = NULL; 
}

template <typename T> 
Node<T>::Node(T data)
{
    this->key = data;
    this->next = NULL; 
}

template <typename T> 
T Node<T>::getData() const 
{
    return this->key; 
}

template <typename T> 
Node<T>* Node<T>::getNext() const 
{
    return this->next; 
}

template <typename T> 
bool Node<T>::setData(T data) 
{
    this->key = data;
    return true; 
}

template <typename T> 
bool Node<T>::setNext(Node<T> *next)
{
    this->next = next;
    return true; 
}

template <typename T> 
bool Node<T>::print() const 
{
    cout << "Data : " << this->key << " Addresss : " << this << " Next Addresss : " << this->next << endl;
    return true; 
}

/**
 * 
 * @name : SinglyLinkedList. 
 * 
*/

template <typename T> 
class SinglyLinkedList 
{
    public:
        SinglyLinkedList();
        bool DeleteNode(T data);
        bool push_back(T data);
        bool pop_back();
        int length() const;
        bool isEmpty() const; 
        bool print() const;
        bool _print() const; // for testing purpose. 
        Node<T>* getHead() const;
        bool setHead(Node<T> *newHead); 

    private:
        Node<T> *head; 
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->head = NULL; 
}

template <typename T> 
bool SinglyLinkedList<T>::push_back(T data)
{
    if(this->head == NULL)
        this->head = new Node<T>(data); 
    else 
    {
        Node<T> *temp = this->head; 
        while(temp->getNext() != NULL) 
        {
            temp = temp->getNext(); 
        }
        temp->setNext(new Node<T>(data)); 
    }

    return true; 
}


template <typename T> 
bool SinglyLinkedList<T>::DeleteNode(T data) 
{
    if(this->head == NULL)
    {
        throw logic_error("List is Empty...");
        return false; 
    }

    Node<T> *previous = this->head, *current = this->head;
    while(current != NULL && current->getData() != data) 
    {
        previous = current;
        current = current->getNext(); 
    }
    if(current == this->head) {
        this->head->setNext(this->head->getNext());
        delete current; 
    } 
    else if(current != NULL) {
        previous->setNext(current->getNext());
        delete current; 
    }
    else 
    {
        throw logic_error("Element not Found...");
        return false; 
    }
    return true; 
}

template <typename T> 
bool SinglyLinkedList<T>::pop_back() {
    if(this->head == NULL)
    {
        throw logic_error("List is Empty.."); 
        return false;
    }
    Node<T> *previous = this->head, *current = this->head;
    while(current->getNext() != NULL)
    {
        previous = current;
        current = current->getNext(); 
    }
    if(current == this->head) 
    {
        this->head = NULL; 
    }
    else 
    {
        previous->setNext(current->getNext()); 
    }
    delete current; 
    return true; 
}

template <typename T> 
int SinglyLinkedList<T>::length() const 
{
    Node<T> *current = this->head;
    int len = 0; 
    while (current != NULL)
    {
        current = current->getNext(); 
        len++;
    }
    return len; 
}

template <typename T> 
bool SinglyLinkedList<T>::isEmpty() const 
{
    return this->head == NULL; 
}

template <typename T> 
bool SinglyLinkedList<T>::print() const 
{
    if(this->head == NULL) 
    {
        cout << "List is Empty.";
        return false;
    }
    Node<T> *temp = this->head; 
    while(temp != NULL)
    {
        cout << temp->getData() << ", ";
        temp = temp->getNext(); 
    }
    cout << endl << endl;
    return true; 
}

template <typename T> 
bool SinglyLinkedList<T>::_print() const 
{
    if(this->head == NULL)
    {
        cout << "List is empty." << endl; 
        return false; 
    }
    Node<T> *temp = this->head; 
    while(temp != NULL)
    {
        temp->print();
        temp = temp->getNext(); 
    }
    return true; 
}

template <typename T> 
Node<T> *SinglyLinkedList<T>::getHead() const 
{
    return this->head; 
}

template <typename T> 
bool SinglyLinkedList<T>::setHead(Node<T> *newHead) 
{
    this->head = newHead;
    return true; 
}

#endif 
