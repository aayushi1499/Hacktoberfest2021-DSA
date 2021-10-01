#include <iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) 
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};
void preorder(struct Node* root)
{
    if(root == NULL)
    {return;}
    //else
    cout<<root->data<<" "; //print root data
    preorder(root->left); //go left, print root, go left until NULL
    preorder(root->right); //go right, print data, go right until NULL
}
void inorder(struct Node* root)
{
    if(root == NULL)
    {return;}
    //else
    inorder(root->left); //go left untill NULL
    cout<<root->data<<" "; //print data
    inorder(root->right); //go right
}
void postorder(struct Node* root)
{
    if(root == NULL)
    {return;}
    //else
    postorder(root->left); //left
    postorder(root->right); //right
    cout<<root->data<<" "; //root
}
void levelorder(struct Node *root)
{
    if(root==NULL)
    {return;}
    //else
    queue<Node*> q; //queue of Node type
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7 */
    q.push(root); //F 1 R
    q.push(NULL); // F 1 NULL R
    while(!q.empty()) //until queue is not Empty
    {
        Node* temp=q.front(); //temp node to traverse queue temp=1
        q.pop(); //pop 1st node from queue F NULL R
        if(temp!=NULL) //
        {
            cout<<temp->data<<" "; //print 1
            if(temp->left) //if there exist left child, push into queue
            {
                q.push(temp->left); 
            }
            if(temp->right) //if there exist right child, push into queue
            {
                q.push(temp->right);
            }
        }
        else if(!q.empty()) //if temp node is NULL, then if queue is not empty, push NULL
        {
            q.push(NULL);
        }
    }
}
int main()
{
    struct Node* root= new Node(1);
    Node* n1=new Node(2);
    root->left=n1;
    Node* n2=new Node(3);
    root->right=n2;
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    return 0;
}