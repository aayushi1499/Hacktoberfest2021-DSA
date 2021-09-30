#include<iostream>
using namespace std;



class Node{
	public:
		int data;
		Node* next;
}*head=NULL;
  
void create(int n);
void insert_beg();
void traverse();
void insert_end();
void insert_pos();
void search();
void del_beg();
void del_end();
void reverse();
void middle();
void occurence();
void get_Nth();
void get_Nth_end(int end);  
void del_Nth_end(int end);

  
int main()
{
	int choice,n,end;
    do{
	cout << "\n1.create\n";
	cout <<"2.insert in the beginning\n";
	cout <<"3.traverse \n";
	cout << "4.insert in the end\n";
	cout << "5.insert after node\n";
	cout << "6.Search\n";
	cout << "7.delete in beg \n";
	cout << "8.delete in end \n";
	cout << "9.reverse the list \n";
	cout << "10.middle element\n";
	cout << "11.count no. of specific element\n";
	cout << "12.to get Nth node\n";
	cout << "13.to get Nth node from the end\n";
	cout << "14.remove Nth node from the end\n";
//	cout << "13.to get Nth node from the end\n";
//	cout << "13.to get Nth node from the end\n";
//	cout << "13.to get Nth node from the end\n";
	cout << "20.exit\n";
	cout << "enter your choice ";
    cin >> choice;
    switch(choice)
    {
    	case 1:
    		    create(n);
    		    break;
        case 2:
        	    insert_beg();
        	    break;
        case 3:	   
			    traverse();
        	    break;
        case 4:	    
				insert_end();
				break;	
		case 5:		
				insert_pos();
				break; 
		case 6:
				search();
				break;
		case 7:
				del_beg();
				break;
		case 8:
				del_end();
				break;
		case 9:
				reverse();
				break;									   
        case 10:  
                middle();
                break;
        case 11:        
                occurence();
                break;
        case 12:        
                get_Nth();
                break;
        case 13:        
                get_Nth_end(end);
                break;
        case 14:        
                del_Nth_end(end);
                break;
        case 20:  
                exit(0);       
		default:
		        cout <<"wrong choice";	
				break;
 }
        }
		while(choice!=20);
}

//create
void create(int n)
{	
Node*temp;
cout << "enter number of nodes ";
cin >> n;
Node*newnode;
int data;
head = (Node*)malloc(sizeof(Node));

if(head==NULL){
	cout << "list is empty";
	
}
cout << "enter data of node 1: ";
cin >> data;
head->data = data;
head->next = NULL;

temp = head;
for(int i=2;i<=n;i++){
newnode = (Node*)malloc(sizeof(Node));
if(newnode == NULL)
{
	cout << "list is empty";
}
cout << "enter data of node" << i << " : ";
cin >> data;

newnode->data = data;
newnode->next = NULL;

temp->next = newnode;
temp = temp->next;
}
}

//traverse
void traverse(){
	Node*temp=head;
	if(head==NULL){
	cout << "list is empty";	
}
	int count = 0;
	cout << "traversal:";
	while(temp!=NULL)
	{
		count++;
		cout << "->" <<temp->data;
		temp=temp->next;
	}
	cout <<"\ncount = " << count <<"\n";
}

//insert in the beginning
void insert_beg(){
	Node* temp, *newnode;
	int data;
		if(head==NULL){
	cout << "list is empty";
	
}
newnode = (Node*)malloc(sizeof(Node));
cout << "enter data of node";
cin >> newnode->data;
newnode->next = head;
head = newnode;
traverse();
}

//insert at the end
void insert_end(){
	Node* temp, *newnode;
	int data;
		if(head==NULL){
	cout << "list is empty";
	
}
newnode = (Node*)malloc(sizeof(Node));
cout << "enter data of node ";
cin >> newnode->data;
newnode->next = NULL ;
temp = head;
while(temp->next != NULL){
	temp=temp->next;
}
temp->next = newnode;
traverse();
}

//insert node after position  
void insert_pos(){
		Node* temp, *newnode;
	int data,pos,i=1;
	cout << "enter desired location:";
	cin >> pos;
		if(head==NULL){
	cout << "list is empty";
}

temp = head;
while(i<pos){
	temp = temp->next;
	i++;
}
newnode = (Node*)malloc(sizeof(Node));
cout << "enter data of node ";
cin >> newnode->data;

newnode->next = temp->next;
temp->next = newnode;
traverse();
}   

//search
void search(){
	Node*temp;
	int val,flag=0;
	cout << "enter data to be searched ";
	cin >> val;
	temp = head;
	while(temp != NULL){
		if(temp->data == val){
			cout << "value found";
			flag++;
		}
		temp=temp->next;
	}
			
	if(flag==0){
	
cout <<"\nnot found";
}			
}

void del_beg(){
	Node*temp;
	temp = head;
	head = head->next;
	free(temp);
	traverse();
}

void del_end(){
	Node*temp,*prev;
	temp = head;
	while(temp->next !=NULL){
		temp= temp->next;
	}
	free(temp);
	
	traverse();
}

//reverse
void reverse(){
	Node*prev,*current,*nextnode;
	prev = nextnode = NULL;
	current = head;
	cout << "reverse:";
	while(current != NULL){
		nextnode = current->next;
		current->next = prev;
		prev = current;
		current = nextnode;	
	}	
	head = prev;
	traverse();	
}    

//middle
void middle(){
	Node*slow,*fast;

	slow = fast = head;
	while(fast!=NULL && fast->next != NULL){
	    slow = slow->next;
	    fast = fast->next->next;
	
	}
    cout << slow->data;
		
}
	
void occurence(){
	Node*temp;
	int val,flag=0;
	cout << "enter data to be searched ";
	cin >> val;
	temp = head;
	while(temp != NULL){
		if(temp->data == val){
			
			flag++;
		}
		temp=temp->next;
	}
			
	if(flag==0){
	
cout << "\nnot found";
}	
cout << flag;	
	
}

void get_Nth(){
	Node*temp;
	int val,flag=0,count=0;
	cout << "enter index of node: ";
	cin >> val;
	temp = head;
	while(temp != NULL){
		
		if(count == val){
			
			flag++;
			cout << temp->data;
		}
		count++;
		temp=temp->next;
	}
			
	if(flag==0){
	
cout << "\nnot found";
}}
	
void get_Nth_end(int end){
	Node*temp;
	temp = head;
	if(head==NULL){
	cout <<"list is empty";	
}

cout << "\nenter n from the end:";
cin >> end;
	int count = 0;
	cout <<"traversal:";
	while(temp!=NULL)
	{
		
		temp=temp->next;
		count++;
	}

if (count < end) 
        return; 
  
    temp = head;

for (int i = 1; i < count - end + 1; i++) 
        temp = temp->next; 

    cout << temp->data; 
  
}	

void del_Nth_end(int end){
	Node*temp;
	temp = head;
	if(head==NULL){
	cout <<"list is empty";	
}

cout << "\nenter n from the end:";
cin >> end;
	int count = 0;
	
	while(temp!=NULL)
	{
		
		temp=temp->next;
		count++;
	}

if (end >= count) {
     Node* ptr=head;
        head=head->next;
        free(ptr);
        traverse();
}
    temp = head;

for (int i = 0; i < count - end - 1; i++) {

        temp = temp->next; 
}
    cout << temp->data << endl; 
   

 Node*t=temp->next;
 temp->next = t->next;
    free(t);
    traverse();
}	
