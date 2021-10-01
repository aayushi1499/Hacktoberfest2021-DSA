/*
Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

        1
      /   \     
    2       3
   /       / \
  4       2   4
         /
        4 
Input: first number of tescase and then tree if there is no child node write N

        1 1 2 3 4 N 2 4 N N 4

Output : 2 4
         4

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 


Node* buildTree(string str)
{   
    
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
   
    Node *root = new Node(stoi(ip[0]));
        
   
    queue<Node*> queue;
    queue.push(root);
        
    
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
       
        Node* currNode = queue.front();
        queue.pop();
            
        
        string currVal = ip[i];
            
        
        if(currVal != "N") {

            
            currNode->left = new Node(stoi(currVal));
                
            
            queue.push(currNode->left);
        }
            
        
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        
        if(currVal != "N") {
                
            
            currNode->right = new Node(stoi(currVal));
                
            
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void preorder(Node* root){
    if(!root){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



unordered_map<string,int>m;
string solve(Node*root,vector<Node*>&v){
    if(!root){
        return "$";
    }
    string s=" ";
    s=s+to_string(root->data);
    s=s+solve(root->left,v);
    s=s+solve(root->right,v);
    m[s]++;
    if(m[s]==2){
        v.push_back(root);
    }
    return s;
}
vector<Node*> printAllDups(Node* root)
{
    
    m.clear();
    vector<Node*>v;
    string s=solve(root,v);
    return v;
}


int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		vector<Node*> res = printAllDups(root);
		
		for(int i=0;i<res.size();i++){
		    preorder(res[i]);
		    cout<<endl;
		}
    }
    return 0;
}

